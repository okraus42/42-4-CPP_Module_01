/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/06 13:41:38 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool ft_readfile(const char *sFileName, std::string &content)
{
	bool	r;
	std::string sLine;
	std::ifstream ifs(sFileName);

	if (!ifs)
		return (false);
	while (std::getline(ifs, sLine))
	{
		content.append(sLine);
		if (ifs.eof())
			break;
		if (ifs.bad())
			return (false);
		content.append("\n");
	}
	r = !ifs.bad();
	ifs.close();
	return (r);
}

void	ft_replace(std::string &content, std::string remove, std::string add)
{
	size_t	pos;
	size_t	nout;
	size_t	nin;

	pos = 0;
	nout = remove.length();
	nin = add.length();
	while (1)
	{
		pos = content.find(remove, pos);
		if (pos == std::string::npos)
			break;
		content.erase(pos, nout);
		content.insert(pos, add);
		pos += nin;
		(void)nin;
	}
}

bool ft_writefile(const char *sFileName, std::string &content)
{
	bool		r;
	std::string	outputfile(sFileName);

	outputfile.append(".replace");
	std::ofstream ofs(outputfile.c_str(), std::ios::out | std::ios::trunc);
	if (!ofs || !ofs.is_open())
		return (false);
	ofs << content;
	r = !ofs.bad();
	ofs.close();
	return (r);
}

int main(int argc, char *argv[]) 
{
	std::string	content;
	if (argc != 4)
	{
		return (1);
	}
	std::string	remove(argv[2]);
	std::string	add(argv[3]);
	if (!ft_readfile(argv[1], content))
	{
		return (1);
	}
	//std::cout << content << std::endl;
	if (argv[2][0] && !content.empty())
		ft_replace(content, remove, add);
	// save new string WriteFile
	//std::cout << content << std::endl;
	if (!ft_writefile(argv[1], content))
	{
		return (1);
	}
	return 0;
}
