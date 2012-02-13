
import java.io.*;

/*
ID: chaoswo1
LANG: JAVA
TASK: friday
*/

public class friday {
	static int is_leap(int y){
		if(y%400==0) return 1;
		if(y%4==0 && y%100!=0) return 1;
		return 0;
	}
	public static void main(String[]args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("friday.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
		
		int n=Integer.parseInt(in.readLine());
		int thirteenth=13;
		int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
		int cnt[]=new int[7];
		for(int i=1900;i<1900+n;++i){
			for(int j=0;j<12;++j){
				thirteenth%=7;
				cnt[thirteenth]++;
				if(j==1) thirteenth+=month[j]+is_leap(i);
				else thirteenth+=month[j];
			}
		}
		out.print(cnt[6]);
		for(int i=0;i<6;++i)
			out.print(" "+cnt[i]);
		out.println();
		out.close();
		
	}
}
