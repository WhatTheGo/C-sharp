public class Zestaw3 {
    public static void main(String[] args){
        System.out.println("Zad1");
        trojkiPitagorejskie(9);
        System.out.println("\nZad2");
        funKwaRozwiazania(3);
        System.out.println("\nZad3");
        funKwaDelta(10);
        System.out.println("\nZad4");
        liczbyPierwsze(100);
        System.out.println("\n\nZad5");
        liczbyPodzielne(1, 2);
        System.out.println("\n\nZad7");
        System.out.println(silnia(5));
        System.out.println("\n\nZad8");
        System.out.println(silniaPodwojna(5));
        System.out.println("\n\nZad13");
        System.out.println(czyPalindrom("kaak"));
        for (int i=0;i<10;i++){
            System.out.println(i + " " + silniaM(i, 3));
        }
    }

    public static boolean czyPalindrom(String txt){
        int txtLen = txt.length();
        for (int i=0; i<txtLen/2; i++){
            if (txt.charAt(0)!=txt.charAt(txtLen-1)){
                return false;
            }
        }
        return true;
    }

    public static int silniaM(int n, int m){
        if (n==0){
            return 1;
        }
        else if (n<m){
            return n;
        }
        return n * silniaM(n-m,m);
    }

    public static int silniaPodwojna(int n){
        if (n==0 || n==1) {
            return 1;
        }
        return n * silniaPodwojna(n-2);
    }
    public static int silnia(int n){
        int wynik=1;
        for (int i=2; i<=n; i++){
            wynik = wynik*i;
        }
        return wynik;
    }

    public static void liczbyPodzielne(int m, int n){
        int liczba = 1;
        for (int i=1; i<m; i++){
            liczba *= 10;
        }
        int koniec = liczba * 10;

        for (liczba = liczba; liczba < koniec; liczba++){
            if (liczba % n == 0){
                System.out.print(liczba + " ");
            }
        }
    }

    public static boolean czyPierwsza(int x){
        for(int i=2; i<=(int) Math.sqrt(x); i++){
            if(x%i==0) { return false; }
        }
        return true;
    }

    public static void liczbyPierwsze(int n) {
        for (int i=2; i<=n; i++){
            if(czyPierwsza(i)) {
                System.out.print(i + " ");
            }
        }
    }

    public static int max(int[] array){
        int max = array[0];
        for (int num: array){
            if (num>max){ max = num; }
        }
        return max;
    }

    public static void trojkiPitagorejskie(int n){
        for (int i=1; i<=n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (i * i + j * j == k * k) {
                        System.out.println(i + " " + j + " " + k);
                    }
                }
            }
        }
    }

    public static void funKwaRozwiazania(int n) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    if (b*b - 4*a*c >= 0) {
                        System.out.println("a=" + a + " b=" + b + " c=" + c);
                    }
                }
            }
        }
    }

    public static void funKwaDelta(int n) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    int delta = b*b - 4*a*c;
                    int deltaSqrt = (int) Math.sqrt(delta);
                    for (int i = 1; i < deltaSqrt ; i++) {
                        if(i*i == delta) {
                            System.out.println("a=" + a + " b=" + b + " c=" + c);
                            break;
                        }
                    }
                }
            }
        }
    }
}
