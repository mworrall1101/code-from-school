import java.util.*;

public class Graph{
	/*The Board class contains the board configuration, as well as the # of adjacent 	boards, and what those boards are*/	
	public static class Board{
		public int[][] b = new int[3][3];
		public int[][][] adj = new int[4][3][3];
		public int numAdjacent = 0;

		public Board(int[][] brd){
			this.b = brd;
		}

		public Board(){
			int[][] temp = {{0,0,0},{0,0,0},{0,0,0}};
			this.b = temp;	
		}
		public int[][] getArr(){
			return b;
		}
		public int numAdjacent(){
			return numAdjacent;
		}
		public int[][][] getAdjacent(){
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 3;j++){
					for(int k = 0; k < 3; k++){
						adj[i][j][k] = b[j][k];
					}
				}		
			}
//top-left			
			if(b[0][0] == 0){
				adj[0][0][0] = adj[0][0][1];
				adj[0][0][1] = 0;
				adj[1][0][0] = adj[1][1][0];
				adj[1][1][0] = 0;
				numAdjacent = 2;
				return adj;
			}
//top-middle
			if(b[0][1] == 0){
				adj[0][0][1] = adj[0][0][0];
				adj[0][0][0] = 0;
				adj[1][0][1] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][0][1] = adj[2][0][2];
				adj[2][0][2] = 0;
				numAdjacent = 3;
				return adj;
			}
//top-right
			if(b[0][2] == 0){
				adj[0][0][2] = adj[0][0][1];
				adj[0][0][1] = 0;
				adj[1][0][2] = adj[1][1][2];
				adj[1][1][2] = 0;
				numAdjacent = 2;
				return adj;
			}
//left-middle			
			if(b[1][0] == 0){
				adj[0][1][0] = adj[0][0][0];
				adj[0][0][0] = 0;
				adj[1][1][0] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][1][0] = adj[2][2][0];
				adj[2][2][0] = 0;
				numAdjacent = 3;
				return adj;
			}
//middle
			if(b[1][1] == 0){
				adj[0][1][1] = adj[0][0][1];
				adj[0][0][1] = 0;
				adj[1][1][1] = adj[1][1][0];
				adj[1][1][0] = 0;
				adj[2][1][1] = adj[2][1][2];
				adj[2][1][2] = 0;
				adj[3][1][1] = adj[3][2][1];
				adj[3][2][1] = 0;
				numAdjacent = 4;
				return adj;
			}
//right-middle
			if(b[1][2] == 0){
				adj[0][1][2] = adj[0][0][2];
				adj[0][0][2] = 0;
				adj[1][1][2] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][1][2] = adj[2][2][2];
				adj[2][2][2] = 0;
				numAdjacent = 3;
				return adj;
			}
//bottom-left
			if(b[2][0] == 0){
				adj[0][2][0] = adj[0][1][0];
				adj[0][1][0] = 0;
				adj[1][2][0] = adj[1][2][1];
				adj[1][2][1] = 0;
				numAdjacent = 2;
				return adj;
			}
//bottom-middle
			if(b[2][1] == 0){
				adj[0][2][1] = adj[0][2][0];
				adj[0][2][0] = 0;
				adj[1][2][1] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][2][1] = adj[2][2][2];
				adj[2][2][2] = 0;
				numAdjacent = 3;
				return adj;
			}
//bottom-right
			if(b[2][2] == 0){
				adj[0][2][2] = adj[0][2][1];
				adj[0][2][1] = 0;
				adj[1][2][2] = adj[1][1][2];
				adj[1][1][2] = 0;
				numAdjacent = 2;
				return adj;
			}

			return adj;
		} 
	}


	HashSet<String> visited = new HashSet<String>();
	int [][] goal = {{1,2,3}, 
			 {4,5,6},
			 {7,8,0}};
	Board goalBoard = new Board(goal);
					 
	boolean dfs(Board cur, ArrayList<String> path){
		String cur_str = new String(Arrays.deepToString(cur.getArr()));		
		if(cur.getArr() == goal){
			System.out.println(path);
			return true;
		}
		//System.out.println(cur_str);
		if(!visited.contains(cur_str)){
			visited.add(cur_str);
			int i;
			int[][][] adj = cur.getAdjacent();
			for(i = 0; i < cur.numAdjacent(); i++){
				path.add(Arrays.deepToString(adj[i]));
				dfs(new Board(adj[i]), path);
				path.remove(Arrays.deepToString(adj[i]));
			}
			//for adjacent nodes 
				//add board to path, 
				//call dfs()
				//remove board from path
		}

		return false;
	}
					
	public static void main(String[] args){
		int[][] start = {{4,0,5},{2,6,1},{7,3,8}};
		Board startBoard = new Board(start);
		/*int[][][] adj = startBoard.getAdjacent();
		System.out.println(Arrays.deepToString(adj[0]));
		System.out.println(Arrays.deepToString(adj[1]));
*/
		ArrayList<String> path = new ArrayList<String>();
		Graph g = new Graph();
	//	g.dfs(startBoard, path);
		if(g.dfs(startBoard, path) == false){
			System.out.println("No Solution");
		}
	}
}
