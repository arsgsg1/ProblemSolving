class Solution {
  static boolean[] visited;
  static int answer = 0;
  static void dfs(int[][] dungeons, int remain, int cnt){
    for(int i = 0; i < dungeons.length; i++){
      if(visited[i] == false && remain >= dungeons[i][0]){
        visited[i] = true;
        dfs(dungeons, remain - dungeons[i][1], cnt + 1);
        visited[i] = false;
      }
    }
    answer = Math.max(answer, cnt);
  }
  public int solution(int k, int[][] dungeons) {
    for(int i = 0; i < dungeons.length; i++){
      visited = new boolean[dungeons.length];
      if(k >= dungeons[i][0]){
        visited[i] = true;
        dfs(dungeons, k - dungeons[i][1], 1);
      }
    }
    return answer;
  }
}