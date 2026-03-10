(
SELECT u.name AS results
FROM MovieRating m
JOIN Users u ON m.user_id = u.user_id
GROUP BY m.user_id
ORDER BY COUNT(*) DESC, u.name
LIMIT 1
)

UNION ALL

(
SELECT mv.title AS results
FROM MovieRating m
JOIN Movies mv ON m.movie_id = mv.movie_id
WHERE DATE_FORMAT(m.created_at,'%Y-%m') = '2020-02'
GROUP BY m.movie_id
ORDER BY AVG(m.rating) DESC, mv.title
LIMIT 1
);