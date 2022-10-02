# minishell

## parsing

- 환경변수를 먼저 파싱해준다. pipex와 같은 방식으로 'PATH='를 찾아준 뒤, ':'을 기준으로 분리해서 저장해준다.

- 명령어의 위치를 봐야할거같다.
	- 명령어의 위치 별로 명령어 앞에 무언가 존재한다면, "<" "<<" 혹은 infile이 올 것이다.



# reference
[bash-manual](https://tiswww.case.edu/php/chet/bash/bashref.html)

[bash-manual-translate](https://github.com/Chanwoong1/42Seoul/blob/master/Circle_3/minishell_md/shell.md)