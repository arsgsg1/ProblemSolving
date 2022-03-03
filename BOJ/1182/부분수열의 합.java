import java.io.*;
import java.util.*;
public class Main {
  public static int[] arr;
  public static int S, N, answer = 0;
  public static void bf(int sum, int toPick, int idx){
    if(toPick == 0){
      if(sum == S){
        answer++;
      }
      return;
    }
    for(int i = idx; i < N; i++){
      sum += arr[i];
      bf(sum,toPick - 1,i + 1);
      sum -= arr[i];
    }
  }
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    S = Integer.parseInt(st.nextToken());
    arr = new int[N];
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }
    for(int i = 1; i <= N; i++){
      bf(0, i, 0);
    }
    System.out.println(answer);
  }
}