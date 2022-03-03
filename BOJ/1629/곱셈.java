import java.io.*;
import java.util.*;
public class Main {
  static int A, B, C;
  //A^4 = A * A * A * A
  //A' = A * A, A' * A' = A^4
  static long pow(int b){
    if(b == 0)
      return 1;
    long temp = pow(b / 2);
    temp = temp * temp % C;
    if(b % 2 == 0)
      return temp;
    return A * temp % C;
  }
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    A = Integer.parseInt(st.nextToken()); B = Integer.parseInt(st.nextToken()); C = Integer.parseInt(st.nextToken());
    System.out.println(pow(B));
  }
}