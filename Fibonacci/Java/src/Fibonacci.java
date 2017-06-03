
public class Fibonacci {
	static int n1=0, n2=1, n3=0;
	static void fibo(int cont){
		if(cont>0){
			n3 =n1+n2;
			n1=n2;
			n2 =n3;
			System.out.print(" "+n3);
			fibo(cont-1);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Salut din Fibonacci");
		int cont =10;
		System.out.print(n1+" "+n2);
		fibo(cont-2);
	}

}
