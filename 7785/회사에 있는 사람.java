import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());
    Set<String> memberSet = new HashSet<>();
    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());
      String name = st.nextToken();
      String order = st.nextToken();
      if(order.compareTo("enter") == 0){
        memberSet.add(name);
      }
      else{
        //O(1)
        memberSet.remove(name);
        //O(n) -> 시간초과
        //memberSet.removeIf(m -> m.compareTo(name) == 0);
      }
    }
    List<String> answerList = memberSet.stream().collect(Collectors.toList());
    Collections.sort(answerList, Collections.reverseOrder());
    answerList.stream().forEach(System.out::println);
  }
}