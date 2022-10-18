import Text.Printf

solve :: Int -> String
solve w
  | w > 2 && even w = "YES"
  | otherwise = "NO"

main :: IO ()
main = do
  w <- getLine
  let wt = (read w :: Int)
  printf "%s\n" $ solve wt
