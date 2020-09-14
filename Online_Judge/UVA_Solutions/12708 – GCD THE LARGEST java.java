/**
 * Created by asif on 8/8/2015.
 */
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.util.Scanner;

class Main{
    public static void main(String [] args){
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(isr);
        StringTokenizer tokenizer = new StringTokenizer("");
        Scanner k = new Scanner(System.in);

        int input = 0;
        int count = k.nextInt() + 1;

        try{
            while(--count > 0){
                if(!tokenizer.hasMoreTokens()){
                    tokenizer = new StringTokenizer(reader.readLine());
                }

                while(tokenizer.hasMoreTokens()){

                    input = Integer.parseInt(tokenizer.nextToken());

                    System.out.println(1000+ input);
                }

            }

        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
