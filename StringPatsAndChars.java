import java.util.HashMap;
import java.util.Map;

// minusPlusPlus given pattern "-++", return a string that outputs this pattern based on 
// int n received. Example n = 7 will output "-++-++-", n = 1 will output "-"
public class test {


    public static String solution(int n){

        String s = "-++";
        String result = "";
        int cycle = n / 3; // cycle of int n by number of String s pattern ("-++")
        int mod = n % 3; // mod leftover after division

        for(int i = 0; i < cycle; i++) {
            result = result.concat(s);
        }
        result = result.concat(s.substring(0, mod));

        
        return result;
    }


    // check for repeating character in a given String. Return character if found, 
    // output "no repeating chars" if not found.
    public static String stringSolution(String s){

        char[] ch = s.toCharArray();
        Map<String, Integer> result = new HashMap<>(ch.length);

        for(int i = 0; i < ch.length; i++){

            if(result.containsKey(String.valueOf(ch[i]))){
                return String.valueOf(ch[i]);
            }
            result.put(String.valueOf(ch[i]), i);
        }
        return "No repeating characters";
    }



    public static void main(String args[]){

        System.out.println(solution(1));
        System.out.println(solution(7));
        System.out.println(solution(10));
        
        System.out.println(stringSolution("aba"));
        System.out.println(stringSolution("abcde"));
        System.out.println(stringSolution("abcdecfg"));
    }

}


