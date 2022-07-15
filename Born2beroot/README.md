# Born2beroot

## Mandatory part

1. 서버 설정
- 운영체제
	- Debian
		- 운영체제 시작 시 AppArmor 또한 구동되어야 함.
- LVM을 이용한 최소 2개의 암호화된 파티션 생성
	- LVM(Logical Volume Manager)은 하나의 디스크를 논리적으로 나누어 사용하거나, 여러개의 디스크를 논리적으로 묶어서 사용하는 등, 리눅스에서 디스크를 효율적으로 관리하기 위한 방법.
		LVM에는 크게 PV, PE, VG, LV, LE라는 개념이 있다.
		- PV (Physical Volume) : 실제로 존재하는 물리 볼륨
		- VG (Volume Group) : PV를 1개 이상 묶어서 그룹화하는 것이다.
		- LV (Logical Volume) : VG에서 논리적으로 Volume을 지정한다. VG의 용량을 초과하여 지정할 수 없다.
		- PE(Physical Extent) 와 LE(Logical Extent)는 각각 PV와 LV를 이루는 최소 단위이고 기본 4MB로 할당되어있다.