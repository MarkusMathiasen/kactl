set ai si is aw ts=4 sw=4 tm=400 nu
sy on | im jk <esc> | im kj <esc> | no ; :
im {<cr> {<cr>b<cr>}<up><right><del>
" Select region and then type :Hash to hash your selection.
" Useful for verifying that there aren't mistypes.
ca hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \
 \| md5sum \| cut -c-6
