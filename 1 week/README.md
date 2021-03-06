**첫 번째 문제**

   반복 문과 순환 호출 2가지 방법을 한 번에 작성했습니다.    



   * **배열 랜덤 초기화 함수**   

       먼저 배열을 랜덤으로 초기화를 시켜주었습니다.

       10개의 정수이므로 중복이 되면 안 되기에, 반복문을 이용해서 검사를 해준 뒤,

       중복 값이 있으면 해당 인덱스의 값을 중복되지 않게 다시 랜덤으로 초기화하도록 작성했습니다.

​

   * **반복문을 이용한 방식**   

       따로 함수로 작성하진 않았습니다.

       초기화된 배열을 순회하면서 초기에 설정해둔 max 값(0)과 비교를 한 뒤,

       max 값보다 큰 값을 초기화하도록 작성

​

   * **순환 호출을 이용한 방식**   

       최댓값을 구하는 방식은 같고

       n이 0이 될 때까지 순환 호출을 한 뒤, 0이 되면 최종 최댓값을 출력

       이 부분은 좀 더 효율적으로 작성할 수 있을 것 같은데 시간 제약이 있어서..

       분석해보고 추후에 수정하겠습니다.

-------------    
   

   

**두 번째 문제**

   b 진수를 표현할 값들(0~~9, A~~F)을 문자열로 먼저 초기화했습니다.


   십진 정수 n을 b 진수로 변환하는 방법은

   n을 b로 나눈 나머지에 해당하는 값을 문자열 str에서 찾아 출력

   ex) 나머지가 2면 str[2] 값인 2출력, 10이면 A 출력    
​

   * **반복문으로 구현한 함수**   

       나머지 연산을 한 값을 미리 선언해둔 배열에 입력한 뒤, 이를 역순으로 출력

   * **순환 호출로 구현한 함수**   

       몫이 0이 될 때까지 나머지 연산한 값을 문자열 str에서 찾아 출력

   * 메인 함수에선 2~16진수만 입력할 수 있도록 조건을 설정하고, 작성한 함수를 호출

------------------    
   

   
   
**세 번째 문제**

   좌표의 개수를 3으로 설정했고, 좌표 구조체(Dot)를 선언한 뒤 초기화했습니다.

​

   * **배열을 이용한 방식**

       * **반복문으로 구현한 함수**   

           선언한 좌표 구조체 배열에서 원점부터 거리를 sum에 누적시킨 뒤
           배열 순회가 끝나면 평균값(sum / MAX)을 반환

       * **순환 호출로 구현한 함수**   

           마찬가지로 순환하면서 거리를 누적시킨 뒤 n=1이면 평균값을 반환하도록 작성

​

   * **연결 리스트를 이용한 방식**   

       단순 연결 리스트를 이용했는데요, 먼저 연결 리스트에 사용할 노트를 선언합니다.

       * **반복문으로 구현한 함수**   

           리스트를 노드 포인터가 NULL을 가리킬 때까지 순회하면서 거리를 누적시킨 뒤 NULL을 가리키면 평균값을 반환하도록 작성

       * **순환 호출로 구현한 함수**   

           반복문과 같은 방식으로 작성