#include"List.h"

int main()
{
	// Josephus problem
	List L;
	initList(L);
	size_t N, M;
	
	std::cout << "Enter num of people N and counter M";
	std::cin >> N >> M;
	for (size_t i = 0; i < N; i++)
	{
		addSort(L, i + 1);
	}
	std::cout << "Initial circle:\n";
	printList(L);
	while (N > 1)
	{
		size_t i = 0;
		for (i = M; N > 1; i += M, N--)
		{
			if (i > N)
				i %= N;
			removePosition(L, i);
		}
	}
	std::cout << "Last num is: ";
	printList(L);

	return 0;
}