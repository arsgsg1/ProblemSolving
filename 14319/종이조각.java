import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N, M;
    static int [][] board = new int[5][5];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int sum = 0, answer = 0;
        for(int i = 0; i < N; i++){
            String str = br.readLine();
            for(int j = 0; j < M; j++){
                board[i][j] = str.charAt(j) - '0';
            }
        }
        for(int i = 0; i < (1 << N * M); i++){
            int cur = i, check = 0, total = 0;
            for(int j = 0; j < N; j++){
                for(int k = 0; k < M; k++){
                    check = j * M + k;
                    if((cur & (1 << check)) != 0){
                        sum = sum * 10 + board[j][k];
                    }
                    else{
                        total += sum;
                        sum = 0;
                    }
                }
                total += sum;
                sum = 0;
            }

            for(int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    check = j + k * M;
                    if ((cur & (1 << check)) == 0) {
                        sum = sum * 10 + board[k][j];
                    } else {
                        total += sum;
                        sum = 0;
                    }
                }
                total += sum;
                sum = 0;
            }
            answer = Math.max(total, answer);
        }
        System.out.println(answer);
    }
}