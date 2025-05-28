int solution(int n) {
    int answer = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {                 // i가 n의 약수인지 검사
            answer += i;                  // 약수 i를 더함
            if (i != n / i) {             // i가 n의 제곱근이 아니면
                answer += n / i;          // 짝꿍 약수도 더함 (n / i)
            }
        }
    }
    return answer;
}
