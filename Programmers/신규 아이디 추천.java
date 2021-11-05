import java.io.*;
import java.util.*;
class Solution {
  public String solution(String new_id) {
    String answer = "";
    String lv1 = new_id.toLowerCase();
    String lv2 = new String();
    for(int i = 0; i < lv1.length(); i++){
      char ch = lv1.charAt(i);
      if(('a' <= ch && ch <= 'z') || ch == '-' || ch == '_' || ch == '.' || ('0' <= ch && ch <= '9')){
        lv2 = lv2.concat(String.valueOf(ch));
      }
    }
    String lv3 = new String();
    int cnt = 0;
    for(int i = 0; i < lv2.length(); i++){
      if(lv2.charAt(i) == '.')
        cnt++;
      else
        cnt = 0;
      if(cnt <= 1)
        lv3 = lv3.concat(String.valueOf(lv2.charAt(i)));
    }
    String lv4 = String.valueOf(lv3);
    if(lv4.startsWith("."))
      lv4 = lv4.substring(1);
    if(lv4.endsWith("."))
      lv4 = lv4.substring(0, lv4.length() - 1);
    String lv5 = String.valueOf(lv4);
    if(lv5.length() == 0)
      lv5 = lv5.concat("a");

    String lv6 = String.valueOf(lv5);
    if(lv6.length() >= 16) {
      lv6 = lv6.substring(0, 15);
      lv6 = lv6.endsWith(".") ? lv6.substring(0, lv6.length() - 1) : lv6;
    }
    String lv7 = String.valueOf(lv6);
    if(lv7.length() <= 2){
      char ch = lv7.charAt(lv7.length() - 1);
      while(lv7.length() != 3){
        lv7 = lv7.concat(String.valueOf(ch));
      }
    }
    answer = lv7;
    return answer;
  }
}