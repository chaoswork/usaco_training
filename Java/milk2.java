import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
ID: chaoswo1
LANG: JAVA
TASK: milk2
*/

/**
 *  first,sort each farmer's milk time with the begin time,
 *  then determine a time interval [s,e],meaning the current time interval always has a cow,
 *  check the sorted milk time,when a new time interval came,only three situations:
 *  1.this farmer's end time still in the [s,e] interval,this doesn't make any sense.
 *  2.this farmer's end time is after e but the begin time still in the [s,e] interval,then update 
 *    the [s,e] interval to [s,current_farmer.endtime],and also update the longest milk time.
 *  3.this farmer's begin time is after e,then the current time interval should update to 
 *    [current_farmer.begintime,current_farmet.endtime],but before this we must update the longest no
 *    milk time by checking the time interval [e,current_farmer.begintime].
 *  when all the farmers time has been checked,we already had the answers.
 *  
 *  
 *  
 */
public class milk2 {
	/**
	 * 
	 * @author huangchao
	 *	the sort method should implement the Comparable interface
	 */
	static class node implements Comparable<node>{
		public int beg;
		public int end;
		public node(){}
		public node(int b,int e){
			beg=b;
			end=e;
		}
		@Override
		public int compareTo(node o) {
			// TODO Auto-generated method stub
			return beg-o.beg;
		}
		
	}
	public static void main(String[]args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("milk2.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));
		
		int n=Integer.parseInt(in.readLine());
		
		node farmers[]=new node[n];
		int i;
		for(i=0;i<n;++i){
			StringTokenizer st=new StringTokenizer(in.readLine());
			farmers[i]=new node(
					Integer.parseInt(st.nextToken()),
					Integer.parseInt(st.nextToken())
					);
		}
		Arrays.sort(farmers);
		
		int s=farmers[0].beg;
		int e=farmers[0].end;
		
		int milk=e-s;
		int nomilk=0;
		for(i=1;i<n;++i){
			if(farmers[i].end<=e){
			}
			else if(farmers[i].beg<=e && farmers[i].end>e){
				e=farmers[i].end;
				if(e-s>milk) milk=e-s;
			}
			else if(farmers[i].beg>e){
				if(nomilk<farmers[i].beg-e) nomilk=farmers[i].beg-e;
				s=farmers[i].beg;
				e=farmers[i].end;
				if(e-s>milk)milk=e-s;
			}
		}
		out.println(milk+" "+nomilk);
		out.close();
		System.exit(0);
		
	}
}
