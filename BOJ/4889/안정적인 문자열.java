import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int tc = 1;
    while(true) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      String str = st.nextToken();
      if(str.charAt(0) == '-')
        break;

      Stack<Character> s = new Stack<>();
      //안정 문자열 제외하기
      for(int i = 0; i < str.length(); i++){
        char ch = str.charAt(i);
        if(!s.empty() && ch == '}' && s.peek() == '{')
          s.pop();
        else
          s.push(ch);
      }
      int answer = 0;
      while(!s.empty()){
        char ch1 = s.peek(); s.pop();
        char ch2 = s.peek(); s.pop();
        if(ch1 == ch2)
          answer += 1;
        else
          answer += 2;
      }
      System.out.println(tc++ + ". " + answer);
    }
  }
}