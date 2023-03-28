/*
** EPITECH PROJECT, 2023
** tailq
** File description:
** basics
*/

#include "list.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void int_printer(void *data) {
    printf("%d ", *(int*)data);
}

bool int_cmp(void *data1, void *data2) {
    return *(int*)data1 == *(int*)data2;
}

void free_int(void *data) {
    free(data);
}

Test(linked_list, basic_operations, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data = malloc(sizeof(int));
    *data = 42;
    ll_add_node_end(list, data);
    cr_assert_eq(TAILQ_FIRST(&list->head)->data, data);
    cr_assert_eq(TAILQ_LAST(&list->head, list_head)->data, data);
    ll_add_node_head(list, data);
    cr_assert_eq(TAILQ_FIRST(&list->head)->data, data);
    cr_assert_eq(TAILQ_LAST(&list->head, list_head)->data, data);
    ll_remove_node(list, TAILQ_FIRST(&list->head));
    cr_assert_eq(TAILQ_FIRST(&list->head)->data, data);
    cr_assert_eq(TAILQ_LAST(&list->head, list_head)->data, data);
    ll_remove_node(list, TAILQ_LAST(&list->head, list_head));
    cr_assert(TAILQ_EMPTY(&list->head));
    ll_is_element_present(list, data, int_cmp);
    ll_free_list(list, free_int);
}

Test(linked_list, print_list, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data = malloc(sizeof(int));
    *data = 42;
    ll_add_node_end(list, data);
    ll_print_list(list, int_printer);
    ll_free_list(list, free_int);
}

Test(linked_list, is_element_present, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data = malloc(sizeof(int));
    *data = 42;
    ll_add_node_end(list, data);
    cr_assert_eq(ll_is_element_present(list, data, int_cmp), true);
    ll_free_list(list, free_int);
}

Test(linked_list, is_element_not_present, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data = malloc(sizeof(int));
    *data = 42;
    int *data2 = malloc(sizeof(int));
    *data2 = 43;
    ll_add_node_end(list, data);
    cr_assert_eq(ll_is_element_present(list, data2, int_cmp), false);
    ll_free_list(list, free_int);
}

Test(linked_list, is_element_present_empty_list, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data = malloc(sizeof(int));
    *data = 42;
    cr_assert_eq(ll_is_element_present(list, data, int_cmp), false);
    ll_free_list(list, free_int);
}

Test(linked_list, ll_get_list_length, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data = malloc(sizeof(int));
    *data = 42;
    ll_add_node_end(list, data);
    cr_assert_eq(ll_get_list_length(list), 1);
    ll_free_list(list, free_int);
}

Test(linked_list, handle_big_list_gestion, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data = malloc(sizeof(int));
    *data = 42;
    for (int i = 0; i < 1000; i++) {
        ll_add_node_end(list, data);
    }
    cr_assert_eq(ll_get_list_length(list), 1000);
    ll_print_list(list, int_printer);
    cr_assert_eq(ll_is_element_present(list, data, int_cmp), true);
}

Test(linked_list, ll_is_element_present_remove, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 20;
    *data2 = 42;
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    ll_is_element_present_remove(list, data1, int_cmp);
    cr_assert_eq(ll_is_element_present(list, data1, int_cmp), false);
    ll_is_element_present_remove(list, data1, int_cmp);
    cr_assert_eq(ll_is_element_present(list, data1, int_cmp), false);
    ll_free_list(list, free_int);
}

Test(linked_list, ll_reverse_list, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 20;
    *data2 = 42;
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    printf("\n\n");
    ll_print_list(list, int_printer);
    ll_reverse_list(list);
    printf("\n");
    ll_print_list(list, int_printer);
}

Test(linked_list, ll_get_nb_elements, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 20;
    *data2 = 42;
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    cr_assert_eq(ll_get_nb_elements(list, data1, int_cmp), 1);
    cr_assert_eq(ll_get_nb_elements(list, data2, int_cmp), 1);
    ll_free_list(list, free_int);
}

Test(linked_list, ll_remove_all_other_occurences, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 20;
    *data2 = 42;
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    ll_add_node_end(list, data2);
    cr_assert_eq(ll_remove_all_other_occurences(list, data1, int_cmp), 3);
    cr_assert_eq(ll_get_nb_elements(list, data1, int_cmp), 1);
    cr_assert_eq(ll_get_nb_elements(list, data2, int_cmp), 4);
}

Test(linked_list, ll_pop_node, .init = redirect_all_std) {
    linked_list_t *list = ll_init_linked_list();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 20;
    *data2 = 42;
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    ll_add_node_end(list, data1);
    ll_add_node_end(list, data2);
    ll_add_node_end(list, data2);
    cr_assert_eq(ll_pop_node(list), data2);
}