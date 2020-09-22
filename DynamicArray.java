/**
https://www.hackerrank.com/challenges/dynamic-array/problem
Function Description 
Complete the dynamicArray function below.

dynamicArray has the following parameters:
- int n: the number of empty sequences to initialize in 
- string queries[q]: an array of query strings

Returns
int[]: the results of each type 2 query in the order they are presented
Input Format

The first line contains two space-separated integers,  (the number of sequences) and  (the number of queries), respectively.
Each of the  subsequent lines contains a query in the format defined above, .

Constraints
It is guaranteed that query type  will never query an empty sequence or index.

Sample Input
2 5
1 0 5
1 1 7
1 0 3
2 1 0
2 1 1
Sample Output
7
3

*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'dynamicArray' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. 2D_INTEGER_ARRAY queries
     */
    public static List<Integer> dynamicArray(int n, List<List<Integer>> queries) {

        List<Integer> result = new ArrayList<Integer>();

        if(n<=0){
            return result;
        }

        List<List<Integer>> seqList = new ArrayList<>(n);
        for(int i=0; i<n;i++){
            seqList.add(new ArrayList<Integer>(1));
        }
        int lastAnswer = 0;
        

        for (List<Integer> query : queries){
            int modIndex = (query.get(1)^lastAnswer)%n;

            if (query.get(0)==1){
                seqList.get(modIndex%n).add(query.get(2));
            }
            
            else if (query.get(0)==2 ){
                lastAnswer = 
            seqList.get(modIndex%n).
            get(query.get(2)%(seqList.get(modIndex%n).size()));
            result.add(lastAnswer);
            }
        }

        return result;

    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int q = Integer.parseInt(firstMultipleInput[1]);

        List<List<Integer>> queries = new ArrayList<>();

        IntStream.range(0, q).forEach(i -> {
            try {
                queries.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> result = Result.dynamicArray(n, queries);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
