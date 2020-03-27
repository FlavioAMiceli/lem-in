/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge_new_del.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 16:48:34 by moana          #+#    #+#                */
/*   Updated: 2020/03/27 18:36:46 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

//TODO add new edge to graph->edge_list
//TODO add connections to graph->vertices
t_edge  *edge_new(char **input_line, t_graph *graph)
{
    t_edge  *edge;
    t_edge  *edge_invert;

    edge = (t_edge*)malloc(sizeof(t_edge));
    edge_invert = (t_edge*)malloc(sizeof(t_edge));
    if (input_line[0] == NULL || input_line[1] == 0 || input_line[2] != 0
        || edge == NULL || edge_invert == NULL)
        return (NULL);
    ft_bzero(edge, sizeof(t_edge));
    ft_bzero(edge_invert, sizeof(t_edge));
    edge->invert = edge_invert;
    edge_invert->invert = edge;
    edge->tail = hmap_get(graph->vertices, input_line[0]);
    edge->head = hmap_get(graph->vertices, input_line[1]);
    if (edge->tail == NULL || edge->head == NULL)
        return (NULL);
    edge_invert->tail = edge->head;
    edge_invert->head = edge->tail;
    return (edge);
}
