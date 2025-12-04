/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:27:18 by kblanche          #+#    #+#             */
/*   Updated: 2025/12/04 19:32:48 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pcolors.h"

#define debugs(STRING) printf("%sDEBUG: [%s%s%s]\n%s", YELLOW, NEUTRAL, STRING, YELLOW, NEUTRAL)
#define debugd(DOUBLE) printf("%sDEBUG: [%s%d%s]\n%s", YELLOW, NEUTRAL, DOUBLE, YELLOW, NEUTRAL)
#define errors(STRING) printf("%sDEBUG: [%s%s%s]\n%s", RED, NEUTRAL, STRING, RED, NEUTRAL)
#define infos(STRING) printf("%sDEBUG: [%s%s%s]\n%s", MAGENTA, NEUTRAL, STRING, MAGENTA, NEUTRAL)
