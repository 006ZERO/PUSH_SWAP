
#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*create_empty_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
	return (stack);
}

t_stack	*create_stack_from_array(int *arr, int count, char name)
{
	t_stack	*stack;
	int		i;
	t_node	*new_node;

	stack = create_empty_stack(name);
	if (!stack)
		return (NULL);
	i = count - 1;
	while (i >= 0)
	{
		new_node = create_node(arr[i]);
		if (!new_node)
		{
			free_stack(stack);
			return (NULL);
		}
		new_node->next = stack->top;
		stack->top = new_node;
		stack->size++;
		if (!stack->bottom)
			stack->bottom = new_node;
		i--;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
