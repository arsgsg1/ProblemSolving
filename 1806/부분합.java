import java.io.*;
import java.util.*;

public class Main {
  private static final int INF = 1000000;
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken()); int S = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    int[] arr = new int[N];
    for(int i = 0; i < N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }
    int l = 0, r = 0, answer = INF, sum = 0;
    while(true){
      if(sum >= S){
        sum -= arr[l++];
        //l == r일 때를 위해 1을 더함.
        answer = Math.min(answer, (r - l) + 1);
      }
      else if(r == N) break;
      else
        sum += arr[r++];
    }
    if(answer == INF) answer = 0;
    System.out.println(answer);
  }
}