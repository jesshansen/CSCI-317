
/**
 * 
 */
import java.util.Scanner;

/**
 * @author jhansen001
 *
 */
public class PiSimulationJava {

 public static void main(String[] args) {
  Scanner reader = new Scanner(System.in);
  System.out.println("Please enter the number of games.");
  float games = reader.nextInt();
  System.out.println("Please enter the amount of darts.");
  float darts = reader.nextInt();
  reader.close();
  // lower bound of random coordinate
  double lower = -0.5;
  // upper bound of random coordinate
  double upper = 0.5;
  // added up total of pi values from all games
  double totalPi = 0;
  // values to help calculate standard deviation
  float standardDev = 0;
  double standardDevTotal = 0;
  float averageStandardDev = 0;
  // average pi value from all games
  float averagePi = 0;
  float pi = 0;
  // loop through all the requested games
  for (int j = 1; j <= games; j++) {
   // count of darts inside the circle each game
   float countInside = 0;
   // loop through requested darts per game
   for (int i = 0; i < darts; i++) {
    // x and y coordinates for each dart
    float x = (float) (Math.random() * (upper - lower) + lower);
    float y = (float) (Math.random() * (upper - lower) + lower);
    // calculates distance for each dart on the board
    float distance = (float) Math.sqrt(x * x + y * y);
    // checks if it made it inside the circle
    if (distance < 0.5) {
     countInside++;
    }
   }
   // calculating pi and standard deviation after each game
   pi = (countInside / darts) * 4;
   totalPi += pi;
   averagePi = (float) (totalPi / j);
   standardDev = (float) Math.pow(pi - averagePi,2);
   // keep a running total of the standard deviations to average out at the end
   standardDevTotal = standardDevTotal + standardDev;
  }

  float variance = (float) standardDevTotal/games;
  averageStandardDev = (float) Math.sqrt(variance); 
  averagePi = (float) (totalPi / games);
  System.out.println("Estimation for pi: " + averagePi);
  System.out.println("\nStandard Deviation: " + averageStandardDev);

 }
}