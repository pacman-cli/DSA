import java.util.*;

public class MazeSolver {

    // Directions for movement (right, left, down, up)
    private static final int[] rowDir = {0, 0, 1, -1};
    private static final int[] colDir = {1, -1, 0, 0};
    private static final int TREASURE = 2;
    private static final int DESTINATION = 3;

    public static void main(String[] args) {
        int[][] maze = {
                {0, 1, 2, 0, 0},  
                {0, 0, 0, 1, 0},
                {0, 3, 1, 0, 0},
                {0, 1, 0, 1, 0},
                {0, 0, 0, 0, 0}
        };

        List<List<int[]>> allPaths = findPaths(maze);
        if (allPaths.isEmpty()) {
            System.out.println("No valid paths found that include the treasure.");
        } else {
            System.out.println("Paths that include the treasure and reach the destination:");
            for (List<int[]> path : allPaths) {
                for (int[] point : path) {
                    System.out.print(Arrays.toString(point) + " -> ");
                }
                System.out.println("END");
            }
        }
    }

    private static List<List<int[]>> findPaths(int[][] maze) {
        List<List<int[]>> allPaths = new ArrayList<>();
        boolean[][] visited = new boolean[maze.length][maze[0].length];
        List<int[]> currentPath = new ArrayList<>();
        boolean foundTreasure = false;

        // Start the DFS from the top-left corner (0, 0)
        dfs(maze, 0, 0, visited, currentPath, allPaths, foundTreasure);

        return allPaths;
    }

    private static void dfs(int[][] maze, int row, int col, boolean[][] visited, List<int[]> currentPath, 
                            List<List<int[]>> allPaths, boolean foundTreasure) {
        // Check boundaries and obstacles
        if (row < 0 || col < 0 || row >= maze.length || col >= maze[0].length || maze[row][col] == 1 || visited[row][col]) {
            return;
        }

        // Mark as visited and add the current position to the path
        visited[row][col] = true;
        currentPath.add(new int[]{row, col});

        // If the current cell is the treasure, mark the treasure as found
        if (maze[row][col] == TREASURE) {
            foundTreasure = true;
        }

        // If we reached the destination and found the treasure, save the path
        if (maze[row][col] == DESTINATION && foundTreasure) {
            allPaths.add(new ArrayList<>(currentPath));
        } else {
            // Explore all 4 possible directions
            for (int i = 0; i < 4; i++) {
                dfs(maze, row + rowDir[i], col + colDir[i], visited, currentPath, allPaths, foundTreasure);
            }
        }

        // Backtrack: unmark the current cell and remove it from the path
        visited[row][col] = false;
        currentPath.remove(currentPath.size() - 1);
    }
  
}
