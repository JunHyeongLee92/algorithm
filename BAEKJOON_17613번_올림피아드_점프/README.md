# 제목
* 점프 (BAEKJOON_17613번)

# 유형
* DP

# 해결 방향
* 각 점프시 점프 길이가 2배로 넓어지게 계산됨
* 문제에서 '마지막 점프'에서 목표 수 x를 지나칠 것 같으면 이라는 말 중요
* 현재 index에서 왼쪽으로 2의 배수의 합(1, 1+2, 1+2+4, ... ) 만큼의 전 위치에서 점프 숫자만큼 더해서 작은값 사용

# 난관
* 런타임 에러 발생
* 배열의 크기를 10^8 까지 밖에 만들지 못함
* 문제는 10^9 이 필요한데 이 값으로 만들면 컴파일 에러 발생
* 비트 연산자를 쓰면 해결할 수 있을 것 같음

# 풀이 날짜
* 2020-01-15

# 출처
* Olympiad > 한국정보올림피아드 > KOI 2019 1차대회 > 고등부 2번
* https://www.acmicpc.net/problem/17613