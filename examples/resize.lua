-- This file is a part of the LibCVC project.
-- It is subject to the license terms in the LICENSE file found
-- in the top-level directory of this distribution.

-- This simple example shows how to resize an image using LibCVC.
-- No external dependencies are required execept for Alien (a Lua binding to libffi).
-- To run:
--  1. Build libcvc
--  2. $ cd examples
--  3. $ export LD_LIBRARY_PATH=$(pwd)/..
--  4. $ luarocks --local install alien
--  5. $ source <(luarocks path)
--  6. $ lua resize.lua

alien = require("alien")

local i,f,d,s,p,ri = "int","float","double","string","pointer","ref int"
local cv = alien.load("libcvc.so")

cv.cv_imread:types{ret = i,s,i,p}
cv.cv_imwrite:types{ret = i,s,p,p}
cv.cv_mat_new:types{ret = i,p}
cv.cv_ints_new:types{ret = i,p}
cv.cv_size_new:types{ret = i,f,f,p}
cv.cv_resize:types{ret = i,p,p,p,d,d,i}

local ptr = alien.buffer(8)

cv.cv_mat_new(ptr)
local mat = ptr:get(1, "pointer")
cv.cv_imread("cat.png", 1, mat)

cv.cv_size_new(100.0, 100.0, ptr)
local size = ptr:get(1, "pointer")
cv.cv_resize(mat, mat, size, 0.0, 0.0, 1)

cv.cv_ints_new(ptr)
local params = ptr:get(1, "pointer")
cv.cv_imwrite("cat.thumbnail.jpg", mat, params)
