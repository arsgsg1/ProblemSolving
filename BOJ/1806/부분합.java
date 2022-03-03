import java.io.*;
import java.util.*;

public class Main {
  private static final int INF = 1000000;
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    Set<String> memberSet = new HashSet<>();
    for(int i = 0; i < N; i++){
      String name = st.nextToken();
      String order = st.nextToken();
      if(order.compareTo("enter")){
        memberSet.add(name);
      }
      else{
        memberSet.removeIf(m -> m.compareTo(name));
      }
    }
    List<String> answerList = new ArrayList<>();
    for(String member : memberSet){
      answerList.add(member);
    }
    Collections.sort(answerList, Collections.reverseOrder());
    for(String member : answerList){
      System.out.println(member);
    }
  }
}