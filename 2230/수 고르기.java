import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken()); int M = Integer.parseInt(st.nextToken());
    int[] arr = new int[N];
    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());
      arr[i] = Integer.parseInt(st.nextToken());
    }
    //정렬하고 투포인터로 범위 좁히면서 탐색
    Arrays.sort(arr);
    long answer = arr[arr.length - 1] - arr[0];
    int l = 0, r = 1;
    while(l <= r && r < arr.length){
      long diff = Math.abs(arr[r] - arr[l]);
      if(diff < M){
        r++;
      }
      else{
        l++;
        answer = Math.min(answer, diff);
      }
    }
    System.out.println(answer);
  }
}