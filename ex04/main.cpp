/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/06 10:38:04 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool ReadFile(const char *sFileName, std::string &content)
{
	std::ifstream ifs(sFileName);
	if (!ifs)
		return (false);
	std::string sLine;
	while (std::getline(ifs, sLine))
	{
		content.append(sLine);
		if (ifs.eof())
			break;
		if (ifs.bad())
			return (false);
		content.append("\n");
	}
	return (!ifs.bad());
}

int main(int argc, char *argv[]) 
{
	std::string	content;
	if (argc < 1)
	{
		return (1);
	}
	if (!ReadFile(argv[1], content))
	{
		return (1);
	}
	std::cout << content << std::endl;
	//replace (if argv[2][0])

	// save new string WriteFile
	return 0;
}