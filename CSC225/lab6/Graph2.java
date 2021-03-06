import java.util.*;

public class Graph2{

	HashSet<String> visited = new HashSet<String>();
	int [][] goal = {{1,2,3},{4,5,6},{7,8,0}};
						 
	boolean dfs(int[][] cur, ArrayList<String> path){	
		if(Arrays.equals(cur[0], goal[0]) && Arrays.equals(cur[1], goal[1]) && Arrays.equals(cur[1], goal[1])){
			System.out.println(path);
			return true;
		}

		//System.out.println(cur_str);
		if(!visited.contains(Arrays.deepToString(cur))){
			visited.add(Arrays.deepToString(cur));
			int numAdjacent = 0,i,j,k;
			int[][][] adj = new int[4][3][3];
			
			for(i = 0; i < 4; i++){
				for(j = 0; j < 3;j++){
					for(k = 0; k < 3; k++){
						adj[i][j][k] = cur[j][k];
					}
				}		
			}
		//top-left			
			if(cur[0][0] == 0){
				adj[0][0][0] = adj[0][0][1];
				adj[0][0][1] = 0;
				adj[1][0][0] = adj[1][1][0];
				adj[1][1][0] = 0;
				numAdjacent = 2;

			}
		//top-middle
			if(cur[0][1] == 0){
				adj[0][0][1] = adj[0][0][0];
				adj[0][0][0] = 0;
				adj[1][0][1] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][0][1] = adj[2][0][2];
				adj[2][0][2] = 0;
				numAdjacent = 3;

			}
		//top-right
			if(cur[0][2] == 0){
				adj[0][0][2] = adj[0][0][1];
				adj[0][0][1] = 0;
				adj[1][0][2] = adj[1][1][2];
				adj[1][1][2] = 0;
				numAdjacent = 2;

			}
		//left-middle			
			if(cur[1][0] == 0){
				adj[0][1][0] = adj[0][0][0];
				adj[0][0][0] = 0;
				adj[1][1][0] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][1][0] = adj[2][2][0];
				adj[2][2][0] = 0;
				numAdjacent = 3;

			}
		//middle
			if(cur[1][1] == 0){
				adj[0][1][1] = adj[0][0][1];
				adj[0][0][1] = 0;
				adj[1][1][1] = adj[1][1][0];
				adj[1][1][0] = 0;
				adj[2][1][1] = adj[2][1][2];
				adj[2][1][2] = 0;
				adj[3][1][1] = adj[3][2][1];
				adj[3][2][1] = 0;
				numAdjacent = 4;

			}
		//right-middle
			if(cur[1][2] == 0){
				adj[0][1][2] = adj[0][0][2];
				adj[0][0][2] = 0;
				adj[1][1][2] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][1][2] = adj[2][2][2];
				adj[2][2][2] = 0;
				numAdjacent = 3;

			}
		//bottom-left
			if(cur[2][0] == 0){
				adj[0][2][0] = adj[0][1][0];
				adj[0][1][0] = 0;
				adj[1][2][0] = adj[1][2][1];
				adj[1][2][1] = 0;
				numAdjacent = 2;

			}
		//bottom-middle
			if(cur[2][1] == 0){
				adj[0][2][1] = adj[0][2][0];
				adj[0][2][0] = 0;
				adj[1][2][1] = adj[1][1][1];
				adj[1][1][1] = 0;
				adj[2][2][1] = adj[2][2][2];
				adj[2][2][2] = 0;
				numAdjacent = 3;

			}
		//bottom-right
			if(cur[2][2] == 0){
				adj[0][2][2] = adj[0][2][1];
				adj[0][2][1] = 0;
				adj[1][2][2] = adj[1][1][2];
				adj[1][1][2] = 0;
				numAdjacent = 2;

			}
		
			for(i = 0; i < numAdjacent; i++){
				path.add(Arrays.deepToString(adj[i]));
				dfs(adj[i], path);
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
		ArrayList<String> path = new ArrayList<String>();
		Graph2 g = new Graph2();
		System.out.println(Arrays.equals(start[0], g.goal[0]));
		if(g.dfs(start, path) == false){
			System.out.println("No Solution");
		}
	}
}
