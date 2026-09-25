DELETE p2 FROM Person p
JOIN Person p2
  ON p.email = p2.email AND p.id < p2.id;