# ft_printf
This function copy (almost) printf.

## Synopsis
`int	ft_printf(const char *format, ...)`

This ft_printf works exactly as the original printf. There are flags available such as: #0-(space)+.

You can use these length modifiers: hh, h, l, ll, j and z.

This function handle these different flags: c, C, s, S, p, d, D, i, u, U, o, O, x and X.

I add also my own: b, which transform decimal into binary notation.

You can use wildcards (useful if you want to manage width and precision in a variable).
