from setuptools import setup, find_packages

setup(
    # 패키지 이름
    name="ft_package",
    # 패키지 버전
    version="0.0.1",
    # 패키지에 포함시킬 모듈과 패키지들의 목록
    # find_packages() 함수는 자동으로 모든 패키지와 서브 패키지를 찾아 목록을 반환한다.
    packages=find_packages(),
    # 패키지 설치에 필요한 다른 패키지들의 목록
    install_requires=[],  # 필요한 경우, 이곳에 의존성 패키지들을 나열한다.
    # 패키지의 메타데이터
    author="chanwjeo",
    author_email="chanwjeo@student.42seoul.kr",
    description="A sample test package",
    # 패키지의 자세한 설명, 여기서는 README.md 파일의 내용을 읽어서 사용하고 있다.
    long_description=open("README.md").read(),
    # 패키지의 자세한 설명 형식, 여기서는 Markdown 형식을 사용하고 있다.
    long_description_content_type="text/markdown",
    # 패키지의 라이선스
    license="MIT",
    # 패키지의 홈페이지 주소
    url="https://github.com/chanwoong1",
    # 패키지의 분류자 목록, 이를 통해 패키지의 메타데이터를 PyPI에 제공한다.
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    # 패키지에 포함되는 데이터 파일을 지정하는 부분 (예: .txt, .md 등의 파일)
    package_data={
        "ft_package": ["*.txt", "*.md"],
    },
)
