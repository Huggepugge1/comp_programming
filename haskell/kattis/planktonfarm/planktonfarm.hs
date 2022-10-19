import Data.List

solve :: Int -> Int -> Int -> Int -> [Int] -> Int
solve p1 p2 a curr l
  | p1 >= p2 = curr
  | (l !! p1) * (l !! p2) >= a = solve (p1 + 1) (p2 - 1) a (curr + 1) l
  | otherwise = solve (p1 + 1) p2 a curr l

main :: IO ()
main = do
  a <- getLine
  b <- getLine
  interact $ show . solve 0 ((read b :: Int) - 1) (read a :: Int) 0 . sort . map read . words
