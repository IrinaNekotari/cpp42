/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:06:51 by nmascrie          #+#    #+#             */
/*   Updated: 2024/10/29 10:06:52 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::~PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe & p)
{
    *this = p;
}

PMergeMe & PMergeMe::operator=(const PMergeMe & p)
{
    this->vec = p.vec;
    this->deq = p.deq;
    return (*this);
}

bool    PMergeMe::check_duplicate()
{
    for (size_t i = 0; i < deq.size(); i++)
    {
        for (size_t j = 0; j < deq.size(); j++)
        {
            if (i != j && deq[i] == deq[j])
                return (true);
        }
    }
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec.size(); j++)
        {
            if (i != j && vec[i] == vec[j])
                return (true);
        }
    }
    return (false);
}

bool    PMergeMe::is_sorted()
{
    for (size_t i = 0; i < deq.size(); i++)
    {
        if (i + 1 > deq.size())
            break ;
        if (deq[i] > deq[i + 1])
            return (false);
    }
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (i + 1 > vec.size())
            break ;
        if (vec[i] > vec[i + 1])
            return (false);
    }
    return (true);
}

void    PMergeMe::init_vector(char **argv)
{
    for (int i = 1; argv[i]; i++)
        vec.push_back(std::atoi(argv[i]));
}

void    PMergeMe::init_deque(char **argv)
{
    for (int i = 1; argv[i]; i++)
        deq.push_back(std::atoi(argv[i]));
}

static int binary_deque(std::deque<int> deque, int right, int element)
{
    int left = 0;
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (element < deque[middle])
			right = middle - 1;
		else if (element > deque[middle])
			left = middle + 1;
		else
			return (middle);
    }
    return (left);
}

static int binary_vector(std::vector<int> vec, int right, int element)
{
    int left = 0;
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (element < vec[middle])
			right = middle - 1;
		else if (element > vec[middle])
			left = middle + 1;
		else
			return (middle);
    }
    return (left);
}

void    PMergeMe::sort_deque()
{
    std::deque<t_tuple> pair;
    std::deque<t_tuple> sorted;
    std::deque<int>     sorted_final;
    bool    has_tail = false;
    int right = 0;
    int index = 0;
    int tail = 0;

    //Separe en pairs
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end() ; it += 2)
    {
        if (it + 1 == deq.end())
        {
            tail = *it;
            has_tail = true;
            break ;
        }
        t_tuple tuple;
        tuple.a = *it;
        tuple.b = *(it+1);
        pair.push_back(tuple);
    }
    //compare les pairs
    for (std::deque<t_tuple>::iterator it = pair.begin(); it != pair.end(); it++)
    {
        if (it->a < it->b)
            std::swap(it->a, it->b);
    }
    //trie les pairs en fonction de leur 1er element
    for (std::deque<t_tuple>::iterator it = pair.begin(); it != pair.end(); it++)
    {
        if (sorted.empty())
        {
            sorted.push_back(*it);
            continue;
        }
        for (std::deque<t_tuple>::iterator it2 = sorted.begin(); it2 != sorted.end(); it2++) 
        {
            if (it->a < it2->a)
            {
                sorted.insert(it2, *it);
                break ;
            }
            if (it2 + 1 == sorted.end()) 
            {
                sorted.push_back(*it);
                break ;
            }
        }
    }
    //insertion
    sorted_final.push_back(sorted[0].b);
    sorted_final.push_back(sorted[0].a);
    for (std::deque<t_tuple>::iterator it = sorted.begin() + 1; it != sorted.end() ;it++)
    {
        sorted_final.push_back(it->a);
        right = sorted_final.size() - 1;
        index = binary_deque(sorted_final, right, it->b);
        sorted_final.insert(sorted_final.begin() + index, it->b);
    }
    if (has_tail)
    {
        right = sorted_final.size() - 1;
        index = binary_deque(sorted_final, right, tail);
        sorted_final.insert(sorted_final.begin() + index, tail);
    }
    deq = sorted_final;
}

void    PMergeMe::sort_vector()
{
    std::vector<t_tuple> pair;
    std::vector<t_tuple> sorted;
    std::vector<int>     sorted_final;
    bool    has_tail = false;
    int right = 0;
    int index = 0;
    int tail = 0;

    //Separe en pairs
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end() ; it += 2)
    {
        if (it + 1 == vec.end())
        {
            tail = *it;
            has_tail = true;
            break ;
        }
        t_tuple tuple;
        tuple.a = *it;
        tuple.b = *(it+1);
        pair.push_back(tuple);
    }
    //compare les pairs
    for (std::vector<t_tuple>::iterator it = pair.begin(); it != pair.end(); it++)
    {
        if (it->a < it->b)
            std::swap(it->a, it->b);
    }
    //trie les pairs en fonction de leur 1er element
    for (std::vector<t_tuple>::iterator it = pair.begin(); it != pair.end(); it++)
    {
        if (sorted.empty())
        {
            sorted.push_back(*it);
            continue;
        }
        for (std::vector<t_tuple>::iterator it2 = sorted.begin(); it2 != sorted.end(); it2++) 
        {
            if (it->a < it2->a)
            {
                sorted.insert(it2, *it);
                break ;
            }
            if (it2 + 1 == sorted.end())  
            {
                sorted.push_back(*it);
                break ;
            }
        }
    }
    //insertion
    sorted_final.push_back(sorted[0].b);
    sorted_final.push_back(sorted[0].a);
    for (std::vector<t_tuple>::iterator it = sorted.begin() + 1; it != sorted.end() ;it++)
    {
        sorted_final.push_back(it->a);
        right = sorted_final.size() - 1;
        index = binary_vector(sorted_final, right, it->b);
        sorted_final.insert(sorted_final.begin() + index, it->b);
    }
    if (has_tail)
    {
        right = sorted_final.size() - 1;
        index = binary_vector(sorted_final, right, tail);
        sorted_final.insert(sorted_final.begin() + index, tail);
    }
    vec = sorted_final;
}

void    PMergeMe::print_all()
{
    std::cout << "# Unsorted : [";
    for (size_t i = 0; i < deq.size(); i++)
    {
        std::cout << deq.at(i);
        if (i + 1 < deq.size())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    start = clock();
    sort_deque();
    time_deq = double(clock() - start) / CLOCKS_PER_SEC;
    std::cout << "# Sorted : [";
    for (size_t i = 0; i < deq.size(); i++)
    {
        std::cout << deq.at(i);
        if (i + 1 < deq.size())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    start = clock();
    sort_vector();
    time_vec = double(clock() - start) / CLOCKS_PER_SEC;
    std::cout << "# Time to sort " << deq.size() << " values in a deque : " << time_deq * 1000 << "ms" << std::endl;
    std::cout << "# Time to sort " << deq.size() << " values in a vector : " << time_vec * 1000 << "ms" << std::endl;
}