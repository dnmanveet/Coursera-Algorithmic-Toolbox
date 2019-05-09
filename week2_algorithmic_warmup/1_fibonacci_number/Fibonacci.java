import java.util.Scanner;

public class Fibonacci {
  private static void calc_fib(int n) {
    int Array[] = new int[n+2];  
    Array[0] = 0;
    Array[1] = 1;
    if(n>1){
    for(int i = 2; i<n; i++){
     Array[i] = Array[i-1]+Array[i-2]; 
    } 
    }  
    for (int i=0; i<=Array.length; i++) {
        System.out.print(Array[i]+" ");
    }
  }

  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    calc_fib(n);
  }
}
