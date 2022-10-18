import Data.List

main :: IO ()
main = getLine >> getLine >>= putStrLn . show . (\x -> length x - length (group x))