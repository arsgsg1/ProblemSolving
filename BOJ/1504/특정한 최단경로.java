import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    while(1){
      Stack<Character> s_st = new Stack<>();
      Stack<Character> b_st = new Stack<>();
      StringTokenizer st = new StringTokenizer(br.readLine());
      String str = st.toString();
      if(str.length() == 1 && str.charAt(0) == '.')
        break;
      for(char ch : str){
        if(ch == '('){
          s_st.push(ch);
        }
        else if(ch == '['){
          b_st.push(ch);
        }
        else if(ch == ')' && !s_st.empty() && s_st.peek() == '('){
          s_st.pop();
        }
        else if(ch == ']' && !b_st.empty() && b_st.peek() == '['){
          b_st.pop();
        }
      }
      if (b_st.size() || s_st.size()) {
        System.out.println("no");
      }
      else{
        System.out.println("yes");
      }
    }
  }
}