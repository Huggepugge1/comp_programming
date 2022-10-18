import Data.List
import Data.String

solve :: Int -> Int -> [Int] -> Int
solve k n c
  | length c == 0 = n
  | (c !! 0) == 0 = n
  | n >= k = n
  | otherwise = solve k (n + c !! 0) (tail c)

main :: IO ()
main = do
  a <- getLine
  let [n, k] = map read $ (words a)
  xs <- getLine
  let ys = map (\x -> length x) $ filter (\x -> (x !! 0) /= "0") $ group $ words xs
  putStrLn $ show $ solve k 0 ys
