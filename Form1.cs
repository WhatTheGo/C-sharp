namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        int[] insertSort(int[] tab)
        {
            for(int i = 1; i < tab.Length; i++)
            {
                for(int j = i; j > 0; j--)
                {
                    int temp = tab[j - 1];
                    if (tab[j] < tab[j - 1])
                    {
                        tab[j - 1] = tab[j];
                        tab[j] = temp;
                    }
                }
            }

            return tab;
        }
        string listToString(int[] tab)
        {
            string napis = "";
            for (int i = 0; i < tab.Length; i++)
            {
                napis += $"{tab[i]} ";
            }
            return napis;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int[] tab1 = { 1, 4, 6, 2, 5, 23, 11 };
            string tab1_str = listToString(tab1);
            MessageBox.Show(tab1_str);
        }
    }
}