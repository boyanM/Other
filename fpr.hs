import Data.List
digits = [0..9]
allPermutations = permutations digits

arg1="send"
arg2="more"
result="money"

count::Char->String->Int
count x [] = 0
count x (y:ys)
 |x == y = 1 + (count x ys)
 |otherwise = count x ys

unique::String->String
unique [] = []
unique list@(x:xs) = if (count x list) == 1 then [x] ++ (unique xs) else unique xs


-- Alphabet => (unique (x ++ y ++ z))
-- zipWith (\x y->(x,y)) (decrypt arg1 arg2 result) (head allPermutation)

checker::String->String->String->String->[Integer]->Bool
checker x y z alphabet perm = False




decrypt::String->String->String->[[Integer]]->[(Char,Integer)]
decrypt x y z [] = []
decrypt x y z perms = if (checker x y z (unique (x ++ y ++ z)) (head perms))
 then [('a',1)]--[zipWith (\x y->(x,y)) (unique (x ++ y ++ z)) (head perms)] ++ (decrypt x y z (tail perms))
 else (decrypt x y z (tail perms))
{-
 if (null perms)
 then [("0asd",0)]
 else
      if (checker x y z (unique (x ++ y ++ z)) (head perms)) 
      then zipWith (\x y->(x,y)) (unique (x ++ y ++ z)) (head perms) ++ (decrypt x y z (tail perms))
      else (decrypt x y z (tail perms))
-}
