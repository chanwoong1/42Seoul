# Born2beroot

## Contents

- [Born2beroot](#Born2beroot)
  - [Contents](#contents)
  - [Mandatory part](#Mandatory-part)
	- [Debian Setup](#Debian-Setup)
	- [sudo setup](#sudo-setup)
	- [AppArmor vs SELinux](#AppArmor-vs-SELinux)
	- [ufw 방화벽 설정](#ufw-방화벽-설정)
	- [ssh 서버 설정](#ssh-서버-설정)
	- [사용자 그룹 설정](#사용자-그룹-설정)
	- [hostname](#hostname)
	- [VM port forwarding](#VM-port-forwarding)
	- [password](#password)
	- [monitoring.sh](#monitoring.sh)
  - [bonus part](#bonus-part))
	- [Partitions](#Partitions)
	- [Setup Wordpress](#Setup-Wordpress)
	- [Link WordPress and MariaDB](#Link-WordPress-and-MariaDB)
  - [Submission and peer-evaluation](#Submission-and-peer-evaluation))
  - [Try](#Try-(125점))
  - [느낀 점](#과제를-수행하며-느낀-점)

## Mandatory part

1. 서버 설정
- 운영체제
	- Debian
		- 운영체제 시작 시 AppArmor 또한 구동되어야 함.
* Debian vs CentOS

	패키지와 패키지 포멧이 다름 (debian : DEB(패키지 포멧), DPKG, API(패키지) / centOS : RPM(패키지 포멧), YUM, DNF(패키지))

* 커널

	운영체제의 주요 구성 요소

	운영체제가 수행하는 모든 것이 저장 되어 있음

	하드웨어의 모든 주요 기능을 제어함

- LVM을 이용한 최소 2개의 암호화된 파티션 생성
	- LVM(Logical Volume Manager)은 하나의 디스크를 논리적으로 나누어 사용하거나, 여러개의 디스크를 논리적으로 묶어서 사용하는 등, 리눅스에서 디스크를 효율적으로 관리하기 위한 방법.
		LVM에는 크게 PV, PE, VG, LV, LE라는 개념이 있다.
		- PV (Physical Volume) : 실제로 존재하는 물리 볼륨
		- VG (Volume Group) : PV를 1개 이상 묶어서 그룹화하는 것이다.
		- LV (Logical Volume) : VG에서 논리적으로 Volume을 지정한다. VG의 용량을 초과하여 지정할 수 없다.
		- PE(Physical Extent) 와 LE(Logical Extent)는 각각 PV와 LV를 이루는 최소 단위이고 기본 4MB로 할당되어있다.

**aptitude VS apt**

Apt : Advanced Packaging Tool
소프트웨어의 설치와 제거를 처리하는 패키지 관리 툴이다. 초기에는 .deb 패키지를 관리하기 위해 만들었지만 현재는 rpm 패키지 매니저와도 호환된다.
apt는 그래픽 인터페이스 없이 명령어로 사용한다.
설치할 패키지 명을 입력하면, '/etc/apt/sources.list'에 지정된 소스 목록에서 해당 패키지 + 종속성 목록과 함께 찾아 자동으로 설치한다. 그렇기 때문에 어떤 패키지를 설치할 때 종속성 문제를 걱정하지 않아도 된다.
또 굉장히 유연해서 사용자가 직접 새로운 소스 목록을 추가하거나 시스템이 업그레이드 되도 해당 패키지를 업데이트 하지 않게 해 현재 버전을 계속 사용하는 등의 작업을 할 수 있다.

Aptitude는 사용자 인터페이스를 추가해 사용자가 대화형으로 패키지를 검색해 설치, 제거할 수 있는 high-level 패키지 관리 도구다. 데비안을 위해 만들어졌지만 rpm 기반 패키지까지 확장된다.
그리고 텍스트 기반 대화형 인터페이스와 비대화형 command line 모드에서도 작동한다.

차이점
Aptitude가 더 방대하고 apt-get, apt-cache를 포함한 기능들을 포함한다.
apt-get이 패키지 설치, 업그레이드, 시스템 업그레이드, 종속성 검사 등을 한다면, aptitude는 이보다 더 많은 일을 할 수 있다. 설치된 패키지 목록, 패키지를 자동 또는 수동으로 설치하도록 표시, 업그레이드에 사용할 수 없는 패키지 보관 등이 있다.

이 외 차이점을 보면,
1. 어떤 패키지를 삭제할 때, aptitude는 사용되지 않는 패키지까지 삭제한다. 반면 apt 는 사용자가 '-auto-remove', 'apt-get autoremove'를 명시해줘야 한다.
2. 이거는 찾아보면서 되게 재밌었던 점인데, aptitude는 'why', 'why-not' 명령어를 이용해 어떤 동작이 왜 안되고 되는지를 볼 수 있다.
3. apt는 설치, 제거 중 충돌이 일어날 경우 종료되지만 aptitude는 해결 방법을 제시할 수 있다.

**SELinux vs AppArmor**

- SELinux - Security Enhanced Linux
	- 관리자가 시스템 액세스 권한을 효과적으로 제어할 수 있게 하는 Linux 시스템용 보안 아키텍처.
```
MAC
시스템 전체에 보안 설정
```
모든 걸 차단하고 필요한 것만 허용한다.

SELinux는 setuid 비트가 켜져 있거나 루트로 실행되는 데몬 프로세스 프로그램들은 샌드박스안에서 별도의 도메인으로 격리되어 낮은 등급으로 실행되므로 루트 권한을 탈취해도 해당 도메인에만 영향을 미치고 전체 시스템에 미치는 영향을 최소화 한다.

-------------------------

- AppArmor - Application Armor
	- 시스템 관리자가 프로그램 프로필 별로 프로그램의 역량을 제한할 수 있게 해주는 리눅스 커널 보안 모듈이다.

```
MAC
개별 응용프로그램을 보호. 응용프로그램 단위 보안.
```

**MAC - 강제접근통제, Mandatory Access Control**

미리 정해진 정책과 보안 등급에 의거하여 주체에게 허용된 접근 권한과 객체에게 부여된 허용 등급을 비교하여 접근을 통제하는 모델.

높은 보안을 요구하는 정보는 낮은 보안 수준의 주체가 접근할 수 없으며 소유자라고 할 지라도 정책에 어긋나면 객체에 접근할 수 없으므로 강력한 보안을 제공한다.

### Debian Setup

디스크 분할에서 수동(Manual 선택)

그 후, 주 영역과 논리 영역으로 파티션 분할. 
![Alt text](./pictures/debian_setup0.png)
논리 영역에서 부팅을 안하는 이유는 논리 영역으로 설정은 했지만 확장 영역에 속해야한다.

확장 영역이란 주 영역에서 사용가능한 영역.

실제 데이터는 저장할 수 없으므로 마운트 불가능.

이와 같이 설정 후, 암호화를 위해 Configure encryped volumns 선택.

create 선택 후, sda5 선택.

그 후 암호화 여러 설정 후, Configure the Logical Volume Manager 선택.

![Alt text](./pictures/debian_setup1.png)

- 마운트 과정 중 LVMGroup - LVhome 선택
![Alt text](./pictures/debian_setup2.png)
Ext4 file system : Ext3 file system을 개선한 버전으로 대용량 파일 시스템을 지원함. Ext3과 호환 가능하므로, Ext4 사용 권장.

마운트 위치도 변경 : 없음 -> /home

- 각각의 그룹을 용도에 맞게 변경
단, swap은 swap area 선택, var-log는 경로 직접 입력으로 /var/log 입력
![Alt text](./pictures/debian_setup3.png)

- GRUB(Grand Unified Bootloader) 부트로더 설정 (YES -> /dev/sda 선택)
부트로더 : 운영 체제가 실행되기 이전에 미리 실행되어 커널이 올바르게 실행될 수 있도록 사전작업을 수행하고, 최종적으로는 아무 이상 없이 운영체제를 실행시키기 위한 프로그램 (부팅의 전 과정을 진행하는 부팅 전문 프로그램을 의미)

여기까지 수행하면 설치를 모두 마치게 된다.
![Alt text](./pictures/debian_setup4.png)

설치 후 접속하여 lsblk 명령어 입력했을 때
![Alt text](./pictures/debian_setup5.png)

### sudo setup

subject의 내용을 충실하게 따라야 하기 때문에 순차적으로 진행한다.

1. root 계정으로 전환

```
su -
```

2. sudo 패키지 설치

```
apt-get install sudo
```

- sudo 패키지 설치 여부
dpkg -l | grep 'sudo'

- sudo log를 저장할 수 있는 디렉토리 생성
```
mkdir /var/log/sudo
```

- sudo 설정
```
visudo
```

설정 창에 들어가면
```
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

Defaults	authfail_message="Authentication attempt failed custom."
Defaults	badpass_message="Wrong password custom."
Defaults	log_input
Defaults	log_output
Defaults	requiretty
Defaults	iolog_dir="/var/log/sudo/"
Defaults	passwd_tries=3
```
로 수정한다.

![Alt text](./pictures/sudo_setup1.png)

* authfail_message

	권한 획득 실패(즉, sudo 인증 실패) 시 출력하는 메세지.

* badpass_messgae

	sudo 인증에서 비밀번호를 틀렸을 시 출력하는 메세지.

* log_input

	sudo 명령어 실행 시 입력된 명령어를 log로 저장하겠다는 설정.

* log-output

	sudo 명령어 실행 시 출력 결과를 log로 저장하겠다는 설정.

* requiretty

	sudo 명령어 실행 시 tty를 강제하는 설정.

* iolog_dir

	sudo log 저장 디렉토리를 지정하는 설정.

* passwd_tries

	sudo 실행 횟수를 지정하는 설정.(default = 3)

log의 경우 sudo 명령어 실행 시 하나씩 저장되게 된다.

log: sudo 실행 시 실행한 위치와 실행한 명령어의 위치 저장

stderr: sudo로 실행한 명령어가 오류로 인해 실행되지 않았을 경우 출력되는 내용 저장

stdin: sudo로 실행한 명령어가 표준 입력을 받은 내용 저장

stdout: sudo로 실행한 명령어가 표준 출력으로 결과를 출력한 내용 저장

timing: session(세션)이 실행된 시간 저장

ttyin: sudo로 실행한 명령어가 TTY로 입력받은 내용 저장

ttyout: sudo로 실행한 명령어가 TTY로 출력한 결과가 저장

vim 설치
```
sudo apt-get install vim
```

### AppArmor vs SELinux

둘 다 관리자가 시스템 엑세스 권한을 효과적으로 제어할 수 있게 하는 security framework이며, 소스코드가 공개되어 있는 리눅스의 보안을 강화하기 위해 만들어졌다.

SELinux는 IBM/RedHat 계열에서 선호되고 같은 계열의 CentOS와 같은 운영체제에서 사용된다. 나머지는 AppArmor를 사용한다.

SELinux는 policy file과 right file system을 통해 작동. AppArmor는 policy file만으로 작동. SELinux가 조금 더 복잡하고 표준화하여 설정하기 어려운 단점.

데비안에서는 기본적으로 깔려 있으나 깔려 있지 않다면 "apt install apparmor apparmor-utils"을 통해 설치 가능.

"aa-enabled" 명령어 통해 활성화 여부 확인 가능

앱아머는 정책 파일을 통해 어떤 어플리케이션이 어떤 파일/경로에 접근 가능한지 허용해준다.

enforce모드와 complain모드 두 가지 존재

enforce 모드 : 허가되지 않은 파일에 접근하는 것을 거부하는 모드

complain 모드 : 실질적으로 보안을 제공하는 것은 아님. 대신 어플리케이션이 해야 할 행동이 아닌 다른 행동을 하는 경우에 앱아머는 
로그를 남겨준다(중지하지는 않음).

"sudo aa-status"통해 현재 상태 확인 가능(enforced, complain, unconfined)

"ps auxZ | grep -v '^unconfined'" 통해 현재 앱아머에 의해 제한된 실행 파일 확인 가능

### ufw 방화벽 설정

<pre><code>
// install ufw
sudo apt install ufw

// ufw 상태 확인 (Default : inactive)
sudo ufw status verbose

// 부팅 시 ufw 활성화
sudo ufw enable

// incoming deny
sudo ufw default deny

// 4242 포트 사용 시 ssh연결 허용
sudo ufw allow 4242

//정책 삭제 원하는 경우 번호 확인 후
sudo ufw status numbered

// 삭제
sudo ufw delete [규칙번호]
</code></pre>

### ssh 서버 설정

**ssh**
두 컴퓨터 간 통신을 할 수 있게 해주는 프로토콜(서로 다른 통신 장비 간 주고 받는 데이터의 양식과 규칙)

ssh의 장점 : 암호화된 통신(client와 host의 통신이 암호화 되어 있음)

모든 데이터가 암호화되어 전송되기 때문에 굉장히 안전하고, 널리 사용되는 이유다.

<pre><code>
// openssh 설치 확인
apt search openssh-server

// 깔려있지 않다면
apt install openssh-server

// openssh 실행 여부, 사용포트 확인
systemctl status ssh

// ssh설정 변경, Port 22 -> Port 4242 변경 후 주석 제거
sudo vim /etc/ssh/sshd_config

// 설정 적용
sudo systemctl restart ssh
</code></pre>

### 사용자 그룹 설정

<pre><code>
// 그룹 추가
groupadd [group name(user42)]

// 특정 사용자 그룹 추가(그룹이 여러개일 경우 공백 없이 콤마로 구분)
usermod -aG [group name(user42)] [user name(chanwjeo)]

// primary group 설정 - 해당 사용자의 홈 디렉토리 내 파일 권한은 자동 변경, 그 외의 파일들은 직접 수정
usermod -g [group name(user42)] [user name(chanwjeo)]

// 특정 사용자 그룹에서 제거
sudo deluser [user name] [group name]

// 특정 사용자 제거
sudo userdel -r [user name]

// 상태 확인
id [username]
</code></pre>

**userdel vs deluser**
- userdel
	- -r :홈 디렉토리 삭제
- deluser
	- --remove : 홈 디렉토리 삭제
	- --remove-all-files : 홈 디렉토리 + 계정명으로 된 모든 파일 삭제

### hostname

<pre><code>
// 호스트명 체크
hostnamectl

// 호스트명 변경 커멘드
sudo hostnamectl set-hostname [바꿀 호스트명]
</code></pre>

### VM port forwarding

가상머신에서 hostname -I로 나오는 주소 기억해둠.

가상머신 종료 후, VirtualBox - Tools - Create 해서 나오는 주소 기억.

다시 가상머신 클릭 후 network - advanced - port fowarding - create

host ip에 vnetbox0의 주소 입력, guest ip에 가상머신의 주소 입력, 포트는 모두 4242 입력

그 후, adapter2로 넘어가서
![Alt text](./pictures/port_forwarding1.png)
과 같이 설정

그 후 터미널에서
```
ssh chanwjeo@***.***.***.*** -p 4242
```
![Alt text](./pictures/port_forwarding1.png)
명령어 입력해주면 접속 가능

root는 접속 불가로 설정

### password

<pre><code>
Your password has to expire every 30 days.
여러분의 비밀번호는 30일마다 소멸되어야 합니다.

The minimum number of days allowed before the modification of a password will be set to 2.
비밀번호 변경을 위해 기다려야 하는 기간은 최소 이틀로 설정되어야 합니다.

The user has to receive a warning message 7 days before their password expires.
유저는 비밀번호 소멸 7일 전에 경고 메시지를 받아야 합니다.

Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.
비밀번호는 최소 10글자 이상이 되어야 하고, 대문자와 숫자를 포함하여야 하며, 같은 글자가 3번 이상 연속되면 안 됩니다.

The password must not include the name of the user.
비밀번호에 유저명이 포함되면 안 됩니다.

The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
다음 규칙은 루트 계정의 비밀번호에 적용되지 않습니다: 비밀번호는 이전 비밀번호에 포함되지 않는 문자를 최소 7개 이상 포함하여야 합니다.

Of course, your root password has to comply with this policy.
당연히, 루트 권한 비밀번호 또한 해당 규칙을 따라야 합니다.
</code></pre>

<pre><code>
// 비밀번호 정책 설정을 위한 패키지 설치
sudo apt install libpam-pwquality

sudo vi /etc/pam.d/common-password


// 다음과 같이 수정
password	requisite	pam_pwquality.so retry=3 minlen=10 difok=7 ucredit=-1 lcredit=-1 dcredit=-1 reject_username enforce_for_root maxrepeat=3

// 강화된 비밀번호로 적용하기 위해 명령어 실행
passwd -e [user_name]

// 설정 변경 이후 강화된 비밀번호가 적용되지 않은 root와 기존 유저에 대해 비밀번호 기간을 설정하기 위해 다음 명령어 실행
change -m 2 -M 30 -W 7 [user_name]


</code></pre>

* retry=3

	비밀번호 입력 횟수 설정, 최대 3회 입력 가능.

* minlen=10

	비밀번호 최소 길이

* difok=7

	이전 비밀번호와 달라야하는 문자 수, root의 경우 이전 비밀번호를 저장하지 않기 때문에 적용되지 않음.

* ucredit=-1

	대문자 제한, -1은 최소 한 글자 이상을 의미함.

* lcredit=-1

	소문자 제한

* dcredit=-1

	숫자 제한

* reject_username

	유저 이름이 그대로 또는 뒤집혀서 비밀번호에 입력될 수 없음

* enforce_for_root

	해당 비밀번호 정책을 root에도 적용

* maxrepeat=3

	중복 글자 제한. 최대 3글자까지 중복 가능

### monitoring.sh

<pre><code>
apt-get -y install sysstat

// monitoring.sh 파일 만들고 아래 내용 입력
vi /root/monitoring.sh

// monitoring.sh
printf "#Architecture: "
uname -a

printf "#CPU physical : "
nproc --all

printf "#vCPU : "
cat /proc/cpuinfo | grep processor | wc -l

printf "#Memory Usage: "
free -m | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

printf "#Disk Usage: "
df -a -BM | grep /dev/map | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"
df -a -BM | grep /dev/map | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "MB ("
df -a -BM | grep /dev/map | awk '{sum1+=$3 ; sum2+=$4 }END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"

printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'

printf "#Last boot: "
who -b | awk '{printf $3" "$4"\n"}'

printf "#LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi

printf "#Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"

printf "#User log: "
who | wc -l

printf "#Network: IP "
hostname -I | tr -d '\n'
printf "("
ip link show | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
printf ")\n"

printf "#Sudo : "
journalctl _COMM=sudo | wc -l | tr -d '\n'
printf " cmd\n"

exit 0
</code></pre>

**monitoring 방법**

```sh
chmod +x monitoring.sh

crontab -e

// 내부 문서에 입력
*/10 * * * * /root/monitoring.sh | wall
```

##  Bonus Part

### Partitions
![Alt text](./pictures/Bonus_part1.png)
정확히 용량까지 맞지는 않지만
![Alt text](./pictures/Bonus_part2.png)
형태를 맞춰주었다.

![Alt text](./pictures/Bonus_part3.png)

### Setup Wordpress

워드프레스를 설치하기 위해서는 PHP를 사용할 수 있는 웹 서버와 데이터베이스 서버가 필요하다.

웹 서버는 Lighttpd, 데이터베이스 서버는 Maria DB로 진행한다.

**setup Lighttpd**
<pre><code>
sudo apt-get install lighttpd

// 서버 중지
sudo systemctl stop lighttpd.service

// 서버 시작
sudo systemctl start lighttpd.service

// 부팅 시 서버 활성화
sudo systemctl enable lighttpd.service
</code></pre>

**setup PHP**

<pre><code>
sudo apt-get install php-fpm

vi /etc/php/7.4/fpm/php.ini

// cgi.fix-path 검색 후
cgi.fix_pathinfo=1 주석 제거

vi /etc/lighttpd/conf-available/15-fastcig-php.conf
// 이 문서에서 "bin-path", "socket" 주석 처리 후 아래 문장 추가
"socket" => "/var/run/php/php7.3-fpm.sock"

// 변경사항 적용 후, 재시작
sudo lighttpd-enable-mod fastcgi 
sudo lighttpd-enable-mod fastcgi-php
service lighttpd force-reload 
</code></pre>

**port 방화벽 해제**

```
vi /etc/lighttpd/lighttpd.conf
```
들어가보면
![Alt text](./pictures/Bonus_part3.png)
기본 설정이 80번 포트로 되어있어서 방화벽을 해제해주어야 한다.

```
ufw allow 80
```

그 후, 포트포워딩을 통해 호스트의 포트 8000과 가상의 포트 80를 연결시켜준다. (워드프레스 접속 경로가 된다)

**setup MariaDB**

MariaDB 접속 시, Unix socket방식으로 인증/접속 (sudo) 하는 방식을 채택하고 있다.
=> mysql의 사용자와 시스템 사용자를 일치시킨다. 이로인해, 항상 sudo를 통해 접속해야 한다.

```sh
// Setup MariaDB
sudo apt install mariadb-server mariadb-client

// DB setting
sudo systemctl stop mysql.service
sudo systemctl start mysql.service
sudo systemctl enable mysql.service

// DB의 root 계정 비밀번호 설정 등 필요한 사항 확인. 모두 Y로 진행해도 됨.
sudo mysql_secure_installation

// 재시작
sudo systemctl restart mysql.service

// Wordpress에 연동할 DB 생성 위해 MariaDB 진입
sudo mysql -u root -p
```

```SQL
// DB 생성
CREATE DATABASE [DB NAME];

// 계정 생성 및 패스워드 설정
CREATE USER '[USER NAME]'@'localhost' IDENTIFIED BY '[PASSWORD]';

// 생성한 DB에 대해 생성한 계정에 full access 부여
GRANT ALL ON [DB NAME].* TO '[USER NAME]'@'localhost' IDENTIFIED BY '[PASSWORD]' WITH GRANT OPTION;

// 설정 저장
FLUSH PRIVILEGES;

EXIT;
```

**Setup WordPress**

워드프레스는 웹사이트를 누구나 쉽게 만들 수 있는 플랫폼이다.

워드프레스를 설치하려면 PHP를 사용할 수 있는 웹서버와 데이터베이스 서버가 필요하다.

```bash
sudo apt-get install wget
sudo wget -O /tmp/wordpress.tar.gz "http://wordpress.org/latest.tar.gz"
sudo tar -xvzf /tmp/wordpress.tar.gz -C /var/www/html
```

### Link WordPress and MariaDB

```
vi /var/www/html/wordpress/wp-config-sample.php
```
위의 경로에서 앞서 설정한 DB NAME, USER NAME, PASSWORD로 고쳐준다.

그 후, 조금 더 밑으로 내려보면,

https://api.wordpress.org/secret-key/1.1/salt/

8줄의 define을 입력하는 부분이 있다. 위의 링크를 통해 들어가서 옮겨 넣어준다.

편집된 내용 저장 후,
```
mv /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpress/wp-config.php
```

여기까지 다 되었다면,

http://localhost:8000/wordpress

를 입력하면

![Alt text](./pictures/Bonus_part5.png)

이와 같은 화면이 뜬다면 정상적으로 설치 완료 된 것이다.

여기 까지 세팅을 하게 되면 보너스 포함 120점을 받을 수 있다.

나머지 5점은 서비스에 관한 부분인데, ftp를 추가적으로 설치하고, 가상서버를 통한 저장소 만들기를 시도해 보는것을 추천한다.

## Submission and peer-evaluation

평가 하기 전, 쓰일만한 명령어를 정리해보았다.

```
// user 한번에 보기
grep /bin/bash /etc/passwd | cut -f1 -d:

// 사용자 비밀번호 변경
sudo passwd <user name>

// 방화벽 포트 상태 확인
ufw status

// hostname
hostname

// 호스트명 체크
hostnamectl

// 호스트명 변경 커멘드
sudo hostnamectl set-hostname [바꿀 호스트명]

// 암호 기한 설정
vi /etc/login.defs

// 암호 체계 설정
vi /etc/pam.d/common-password

// 비밀번호 오류로 인한 지정 메세지 표시
sudo visudo

// sudo를 사용하는 명령의 입,출력을 모두 보관하는 디렉토리
cd /var/log/sudo
```

## Try (125점)

평가를 진행하기 전, 원할한 평가를 위해 평가 표를 한번 보았다. 100% 동료평가만으로 채점이 이루어지기 때문에, 평가표가 시키는 작업들을 무리없이 수행할 수 있도록 하는것을 목표로 하였다.

또한, 리눅스 운영체제에 관한 정보나, apt, apparmor등 낯선 용어들을 평가자들에게 설명해야하므로, 개념적인 부분을 이해하는 데에 주력했다.

그리고 그동안 모아왔던 정보나, 명령어들을 외워서 사용하는것이 힘들어서 명령어들만 따로 정리해서 평가자들에게 양해를 구하고, 기억나지 않는 명령어들은 찾아보며 평가를 진행했다.

## 과제를 수행하며 느낀 점

리눅스 운영체제에 대해 이해할 수 있는 시간이 되었고, 일주일간 코딩 없이 Born2beroot만 한다는 것이 힘들기도 했지만 끝내고 나니 후련했다. 또, ssh를 통해 가상 환경과 호스트 환경을 연결하여 맥 터미널에서 가상 환경의 명령을 수행할 수 있도록 하는것이 신기했다. 향후 과제들 중에는 서버를 사용하는 과제들이 또 있다고 들었는데, 시간을 들여 과제를 수행한 만큼 다음 과제도 열심히 할 수 있는 계기가 된 것 같다.