/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:16:47 by amsbai            #+#    #+#             */
/*   Updated: 2025/02/28 11:17:46 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libftprintf/libftprintf.h"
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *s, ...);

#endif