#include <stdio.h>
#include <stdlib.h>

void	find_subsets(int *nums, int *sub, int count, int sub_size, int pos, int sum, int target)
{
	if (sum == target)
	{
		int i = 0;
		while (i < sub_size)
		{
			printf("%d", sub[i]);
			if (i < sub_size - 1)
				printf(" ");
			i++;
		}
		printf("\n");
	}
	while (pos < count)
	{
		sub[sub_size] = nums[pos];
		find_subsets(nums, sub, count, sub_size + 1, pos + 1, sum + nums[pos], target);
		pos++;
	}
}

void	powerset(int ac, char **av)
{
	int	target = atoi(av[1]);
	int	count = ac - 2;
	int	*nums = malloc(sizeof(int) * count);
	int	*sub = malloc(sizeof(int) * count);
	
	if (!nums || !sub)
	{
		if (nums)
			free(nums);
		if (sub)
			free(sub);
		return;
	}
	
	int i = 0;
	while (i < count)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	
	find_subsets(nums, sub, count, 0, 0, 0, target);
	free(nums);
	free(sub);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	powerset(ac, av);
	return (0);
}