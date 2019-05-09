import java.util.Scanner;

public class Change {
    private static int getChange(int m) {
        int[] coinNames = {10,5,1};
        int qtyCoins = 0;
      
        while(m > 0){
	      for(int i = 0; i < coinNames.length; i++){
               if(m >= coinNames[i]){
		         m -= coinNames[i];
                    qtyCoins++;
                    break;
              	}
          	}
       }
       return qtyCoins;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        System.out.println(getChange(m));

    }
}

