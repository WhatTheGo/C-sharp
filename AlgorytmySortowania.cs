using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace AlgorytmySortowania
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int[] tab1;
        private void button1_Click(object sender, EventArgs e)
        {
            int n = Int32.Parse(textBox1.Text);
            tab1 = new int[n];
            Random rnd = new Random();
            for (int i = 0; i < n; i++)
            {
                int num = rnd.Next(9);
                tab1[i] = num;
            }
            niePosortowane.Text = ListToString100(tab1);
        }

        string ListToString100(int[] tab)
        {
            string napis = "";
            int n;
            if (tab.Length > 100)
            {
                n = 100;
            }
            else { n = tab.Length; }

            for (int i = 0; i < n; i++)
            {
                napis += $"{tab[i]} ";
            }
            return napis;
        }

        void BubbleSort(int[] tab)
        {
            int n = tab.Length;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (tab[j] > tab[j + 1])
                    {
                        (tab[j + 1], tab[j]) = (tab[j], tab[j + 1]);
                    }
                }
            }
        }
        void InsertSort(int[] tab)
        {
            int n = tab.Length;
            for (int i = 1; i < n; i++)
            {
                int tmp = tab[i];
                int j = i - 1;
                while (j >= 0 && tab[j] > tmp)
                {
                    tab[j + 1] = tab[j];
                    j--;
                }
                tab[j + 1] = tmp;
            }
        }

        void QuickSort(int[] tab, int left, int right)
        {
            if (right <= left) return;
            int pivotIndex = Partition(tab, left, right);
            QuickSort(tab, left, pivotIndex - 1);
            QuickSort(tab, pivotIndex + 1, right);

        }

        int Partition(int[] tab, int left, int right)
        {
            int pivot = tab[right];
            int i = left - 1;

            for (int j = left; j <= right - 1; j++)
            {
                if (tab[j] < pivot)
                {
                    i++;
                    (tab[j], tab[i]) = (tab[i], tab[j]);
                }
            }
            i++;
            (tab[i], tab[right]) = (tab[right], tab[i]);
            return i;
        }

        void CountingSort(int[] tab)
        {
            int n = tab.Length;
            int maxElement = tab.Max();
            int[] occurences = new int[maxElement + 1];

            for (int i = 0; i <= maxElement; i++)
            {
                occurences[i] = 0;
            }

            for (int i = 0; i < n; i++)
            {
                occurences[tab[i]]++;
            }

            for (int i = 0, j = 0; i <= maxElement; i++)
            {
                while (occurences[i] > 0)
                {
                    tab[j] = i;
                    j++;
                    occurences[i]--;
                }
            }
        }

        void MergeSort(int[] tab)
        {
            int n = tab.Length;
            if (n <= 1) { return; }

            int middle = n / 2;
            int[] leftTab = new int[middle];
            int[] rightTab = new int[n - middle];

            int j = 0;
            for (int i = 0; i < n; i++)
            {
                if (i < middle)
                {
                    leftTab[i] = tab[i];
                }
                else
                {
                    rightTab[j] = tab[i];
                    j++;
                }
            }

            MergeSort(leftTab);
            MergeSort(rightTab);
            Merge(leftTab, rightTab, tab);
        }

        void Merge(int[] leftTab, int[] rightTab, int[] tab)
        {
            int l = 0, r = 0, i = 0;
            while (l < leftTab.Length && r < rightTab.Length)
            {
                if (leftTab[l] < rightTab[r])
                {
                    tab[i] = leftTab[l];
                    l++;
                    i++;
                }
                else
                {
                    tab[i] = rightTab[r];
                    r++;
                    i++;
                }
            }

            while (l < leftTab.Length)
            {
                tab[i] = leftTab[l];
                l++;
                i++;
            }
            while (r < rightTab.Length)
            {
                tab[i] = rightTab[r];
                r++;
                i++;
            }
        }

        void BubbleSort2(int[] tab)
        {
            int n = tab.Length;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (tab[j] > tab[j + 1])
                    {
                        (tab[j], tab[j + 1]) = (tab[j + 1], tab[j]);
                    }
                }
            }
        }

        void InsertSort2(int[] tab)
        {
            int n = tab.Length;
            for (int i = 1; i < n; i++)
            {
                int j = i - 1;
                int temp = tab[i];
                while (j >= 0 && temp < tab[j])
                {
                    tab[j + 1] = tab[j];
                    j--;
                }
                tab[j + 1] = temp;
            }
        }

        void QuickSort2(int[] tab, int start, int end)
        {
            if (end <= start) return;
            int pivotIndex = Partition2(tab, start, end);
            QuickSort(tab, start, pivotIndex - 1);
            QuickSort(tab, pivotIndex + 1, end);
        }

        int Partition2(int[] tab, int start, int end)
        {
            int pivot = tab[end];
            int i = start - 1;
            for (int j = start; j < end; j++)
            {
                if (tab[j] < pivot)
                {
                    i++;
                    (tab[j], tab[i]) = (tab[i], tab[j]);
                }
            }
            i++;
            (tab[end], tab[i]) = (tab[i], tab[end]);
            return i;
        }

        private void BubbleSortButton_Click(object sender, EventArgs e)
        {
            BubbleSort(tab1);
            posortowane.Text = ListToString100(tab1);
        }

        private void InsertSortButton_Click(object sender, EventArgs e)
        {
            InsertSort(tab1);
            posortowane.Text = ListToString100(tab1);
        }

        private void QuickSortButton_Click(object sender, EventArgs e)
        {
            QuickSort(tab1, 0, tab1.Length - 1);
            posortowane.Text = ListToString100(tab1);
        }

        private void CountingSortButton_Click(object sender, EventArgs e)
        {
            CountingSort(tab1);
            posortowane.Text = ListToString100(tab1);
        }

        private void MergeSortButton_Click(object sender, EventArgs e)
        {
            MergeSort(tab1);
            posortowane.Text = ListToString100(tab1);
        }
    }
}
