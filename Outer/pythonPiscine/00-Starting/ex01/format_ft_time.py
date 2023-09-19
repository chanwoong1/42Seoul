import time
import datetime


def format_number_with_commas(num):
    return "{:,.4f}".format(num)


# 현재 시간을 Unix timestamp 형태로 가져옴
seconds_since_epoch = time.time()

# 현재시간을 출력 양식으로 변환
formatted_number = format_number_with_commas(seconds_since_epoch)
print(f"Seconds since January 1, 1970: {formatted_number}", end="")
print(f" or {seconds_since_epoch:.2e} in scientific notation")

# 해당 시간을 datetime 객체로 변환
dt = datetime.datetime.fromtimestamp(seconds_since_epoch)

# Oct 21 2022 형식으로 시간 출력
print(dt.strftime("%b %d %Y"))
