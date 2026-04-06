
class Sort
{
public:
	Sort();
	~Sort();
    static void sort(int* arr, int lenght) {

        for (int k = 0; k < lenght - 1; k++)
        {
            for (int i = 0; i < lenght - 1; i++) {
                if (arr[i] > arr[i + 1])
                {
                    int swap = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = swap;
                }


            }
        }
        return;
    }
private:

};

Sort::Sort()
{
}

Sort::~Sort()
{
}