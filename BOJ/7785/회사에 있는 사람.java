import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
  public static int binarySearch(List<?> list, int target){
    int st = 0, en = list.size();
    while(st <= en){
      int mid = (st + en) / 2;
      if(list.get(mid) < target)
        st = mid + 1;
      else if(list.get(mid) > target)
        en = mid - 1;
      else {
        if(list.get(mid) == target)
          return mid;
        else
          return -1;
      }
    }
  }
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    Set<Integer> set = new HashSet<>();
    for(int i = 0; i < N; i++)
      set.add(Integer.valueOf(st.nextToken()));

    List<Integer> list = set.stream().collect(Collectors.toList());
    Collections.sort(list);
    list.stream().forEach(i -> System.out.println(binarySearch(i)));
  }
}