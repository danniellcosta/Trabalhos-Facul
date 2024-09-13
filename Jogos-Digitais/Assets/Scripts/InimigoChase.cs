using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InimigoChase : InimigoComportamento
{
    public float distanciaDeVerificacao = 1.0f; // Defina o valor apropriado
    public LayerMask layerMask; // Defina a camada apropriada

    private Transform player; // Reference to the player's transform
    private Node node; // Reference to the node component

    private void Start()
    {
        // Assuming the player has a tag "Player"
        player = GameObject.FindGameObjectWithTag("Muscleman").transform;
        node = GetComponent<Node>();
    }

    private void OnDisable()
    {
        this.inimigo.scatter.Enable();
    }

    private void OnEnable()
    {
        StartCoroutine(UpdateMovementDirection());
        inimigo.scatter.Disable();
    }

    private IEnumerator UpdateMovementDirection()
    {
        while (this.enabled && !this.inimigo.assustado.enabled)
        {
            if (node != null)
            {
                // Filtra as direções disponíveis para aquelas que não têm paredes
                List<Vector2> direcoesValidas = new List<Vector2>();
                foreach (Vector2 direcao in node.DirecoesDisponiveis)
                {
                    Vector2 start = transform.position;
                    Vector2 end = start + direcao * distanciaDeVerificacao;

                    // Executa o Raycast para verificar se há paredes na direção
                    RaycastHit2D hit = Physics2D.Raycast(start, direcao, distanciaDeVerificacao, layerMask);
                    if (hit.collider == null)
                    {
                        direcoesValidas.Add(direcao);
                    }
                }

                if (direcoesValidas.Count > 0)
                {
                    // Encontra a direção mais próxima do player
                    Vector2 closestDirection = FindClosestDirection(direcoesValidas, player.position);

                    this.inimigo.movimento.SetDirecao(closestDirection);

                    Debug.Log($"Nova direção: {closestDirection}");
                }
                else
                {
                    Debug.Log("Nenhuma direção válida encontrada sem paredes.");
                }
            }

            yield return new WaitForFixedUpdate(); // Wait for the next fixed update
        }
    }

    private Vector2 FindClosestDirection(List<Vector2> directions, Vector2 targetPosition)
    {
        Vector2 closestDirection = directions[0];
        float minDistance = float.MaxValue;

        foreach (Vector2 direction in directions)
        {
            Vector2 directionVector = direction * distanciaDeVerificacao;
            Vector2 currentPosition = new Vector2(transform.position.x, transform.position.y);
            Vector2 newPosition = currentPosition + directionVector;
            float distance = Vector2.Distance(newPosition, targetPosition);

            if (distance < minDistance)
            {
                minDistance = distance;
                closestDirection = direction;
            }
        }

        return closestDirection;
    }
}
