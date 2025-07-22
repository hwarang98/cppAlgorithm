int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack; // 스택을 사용하여 재료를 저장

    
    for (int i = 0; i < ingredient.size(); i++) {
        stack.push_back(ingredient[i]);
        if (stack.size() >= 4) {
            // 스택의 맨 위부터 4개의 재료를 확인하여 빵 -> 야채 -> 고기 -> 빵의 순서인지 확인
            if (stack[stack.size() - 4] == 1 && stack[stack.size() - 3] == 2 && stack[stack.size() - 2] == 3 && stack[stack.size() - 1] == 1) {
                answer++;
                // 빵 -> 야채 -> 고기 -> 빵의 순서가 맞으면 스택에서 해당 재료를 제거
                for (int j = 0; j < 4; j++) {
                    stack.pop_back();
                }
            }
        }
    }
    
    return answer;
}
